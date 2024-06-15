#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return
source /etc/profile
PS1='\u [\w] > '

# TERMINAL PREP
date
echo "Welcome to the terminal."

# ALIASES
alias skytemple="~/.local/bin/skytemple"
alias cl="clear"
alias cleangittree="git clean -d -f -x"

PATH="$PATH:/usr/bin:/usr/sbin:/bin:/sbin:/usr/local/bin:/usr/local/sbin:~/.local/bin:/opt/lilypond/bin:/usr/local/cuda/bin"
