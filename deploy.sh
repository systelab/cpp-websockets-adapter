#!/bin/bash

function checkErrors
{
	if [ $? != 0 ]
	then
		echo 
		echo "An error occured while deploying artifacts."
		echo
		exit 1
	fi
}

function parseParameters
{
	VERSION="None"
	while getopts "hv:" OPTION
	do
		case $OPTION in
		h)
			usage #help: show usage section
			exit 0
			;;
		v)
			VERSION=$OPTARG
			;;
		?)
			echo "Invalid parameter" 
			usage
			exit 1
			;;
		esac
	done
	
	echo "********** DEPLOY PARAMETERS **********"
	echo "VERSION: $VERSION"
}

parseParameters "${@}"

echo -e "\nUploading WebSocketsAdapterInterface/$VERSION@systelab/stable to systelab-bintray...\n\n"
conan upload "WebSocketsAdapterInterface/$VERSION@systelab/stable" --all -r systelab-bintray --force
checkErrors

echo -e "\nUploading WebSocketsAdapterTestUtilities/$VERSION@systelab/stable to systelab-bintray...\n\n"
conan upload "WebSocketsAdapterTestUtilities/$VERSION@systelab/stable" --all -r systelab-bintray --force
checkErrors
