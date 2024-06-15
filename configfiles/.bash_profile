#
# ~/.bash_profile
#

[[ -f ~/.bashrc ]] && . ~/.bashrc
export GTK_IM_MODULE='fcitx'
export QT_IM_MODULE='fcitx'
export SDL_IM_MODULE='fcitx'
export XMODIFIERS='@im=fcitx'
export EMULATORS='dolphin-emu mupen64plus-qt desmume'
export N64_EMU="mupen64plus-qt"
export CG_EMU="dolphin-emu"
export DS_EMU="desmume"
export MAKEFLAGS='-j12'
#export MESA_VK_VERSION_OVERRIDE="1.3"
#export MESA_LOADER_DRIVER_OVERRIDE=zink
