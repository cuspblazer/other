#!/bin/bash
# Description: Extract url from name of the video and return it to the user.
# 	       User can also download the found video as audio track.
# Note: don't judge me. it's my firt script

query=""
curl_path=$(which curl)
json_list=""
json_element_properties=""
url=""
index=0
download=0
if [ $# -eq 1 ]; then
	echo "Track info mode"
	query=$(echo $1 | tr " " "+")
elif [ $# -eq 2 ] && [ "$(echo $1)" == "-d" ]; then
	echo "Download track mode"
	query=$(echo $2 | tr " " "+")
	yt_dlp_path=$(which yt-dlp)
	download=1
else
	echo "Unrecognized argument. Exiting..."
fi
yt_link="https://api.yt.jae.fi/search?q=$query&filter=all" # filter=music_songs

function extract_json() {
	json_list=$($curl_path -s $yt_link)
}
function extract_element_properties() {
	json_element_properties=$(echo $json_list | jq '.["items"]['$index']') # Extracts only properties the one element
}
function extract_watch_link() {
	# Check if the current element is a stream. If not, check the next element
	if [ "$(echo $json_element_properties | jq -r '.["type"]')" != "stream" ]; then
		index=$(($index+1))
		extract_element_properties # Update variable json_element_properties
		extract_watch_link # Try again
	else
		url=$(echo $json_element_properties | jq -r '.["url"]')
	fi
}
function print_track_info() {
	echo "Title: $(echo $json_element_properties | jq -r '.["title"]')"
	echo "Uploader: $(echo $json_element_properties | jq -r '.["uploaderName"]')"
	echo "Duration: $(($(echo $json_element_properties | jq -r '.["duration"]') / 60)):$(($(echo $json_element_properties | jq -r '.["duration"]') % 60))"
	echo "URL: https://youtu.be$url"
}
function main() {
	extract_json
	# Check for search errors
	if [ "$(echo $json_list | jq -r '.["error"]')" != "null" ]; then
		echo "A search error occurred. Exiting..."
		echo $json_list
		return -1
	elif [ "$(echo $json_list | jq -r '.["items"]')" == "null" ]; then
		echo "No tracks found. Exiting..."
		return -1
	fi
	extract_element_properties
	extract_watch_link
	print_track_info	
	if [ $download -eq 1 ]; then 	
		echo "Downloading track..."
		$yt_dlp_path -x "https://youtu.be$url"
	fi
}
main
