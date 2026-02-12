Installation Instructions
Prerequisites
The target machine needs:

Linux/Unix operating system (or WSL on Windows)
GCC compiler (gcc)
ncurses development library (libncurses-dev or ncurses-devel)
make utility
Step-by-Step Installation
1. Install dependencies (if not already installed):

bash
# On Debian/Ubuntu:
sudo apt-get update
sudo apt-get install build-essential libncurses-dev
# On Fedora/RHEL/CentOS:
sudo dnf install gcc make ncurses-devel
# On Arch Linux:
sudo pacman -S base-devel ncurses
2. Copy the game files:

Transfer the entire /home/louie/Desktop/sandbox/zthief/zthief directory to the target machine. You can use:

SCP: scp -r /home/louie/Desktop/sandbox/zthief/zthief user@targetmachine:/path/to/destination
rsync: rsync -avz /home/louie/Desktop/sandbox/zthief/zthief user@targetmachine:/path/to/destination
USB drive: Copy the folder to a USB drive and transfer
Git: If you have it in a repository, just clone it
3. Compile on the target machine:

bash
cd /path/to/zthief
make clean  # Clean any old build files
make        # Compile the game
4. Run the game:

bash
./xrogue
Important Notes
Terminal requirements: The terminal must support colors (most modern terminals do)
Screen size: Minimum 80x24 terminal recommended for best experience
Permissions: Make sure the xrogue binary is executable (chmod +x xrogue if needed)
Quick Test
To verify everything works:

Run ./xrogue
Press @ to see the color-coded legend
Look for colored monsters (red/green) and items (various colors)
Check the sidebar on the right showing nearby objects
That's it! The game should work identically on any Linux machine with the proper dependencies installed.