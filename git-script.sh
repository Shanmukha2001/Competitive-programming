#!/bin/bash
# Show the status of the current git repository
git status
# Ask for a commit message from the user
read -p "Enter your commit message: " message
# Commit the changes with the given message
git add .
git commit -m "$message"
# Ask the user if they want to push to origin main
read -p "Do you want to push to origin main? (y/n) " answer
# If the answer is yes, push the changes
if [ "$answer" = "y" ]; then
  git push origin main
fi
if [ "$answer" = "n" ]; then
    read -p "Enter origin name: " message
    git push origin "$message"
fi

