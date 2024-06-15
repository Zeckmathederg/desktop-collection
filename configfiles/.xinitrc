#~/.xprofile
#xrandr --output DP-3 --mode 1920x1080_165.00
xset s off &
pulseaudio --start &
#compton -f -b &
picom -b --vsync --animations --animation-stiffness=100 --animation-for-open-window=zoom
# The above line uses a fork of picom made by Pijulius @
# https://github.com/pijulius/picom
# Performance is bad for Nouveau in my experience.
feh --bg-fill ~/Pictures/Desktop/zeckma-banner-update1-prog1.png &
exec dwm
