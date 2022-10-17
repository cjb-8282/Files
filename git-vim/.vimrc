set nocompatible    
filetype off       

" let Vundle manage Vundle
set rtp +=~/.vim/bundle/Vundle.vim/
call vundle#begin()
" My Bundles here:
" required
Plugin 'VundleVim/Vundle.vim'

" User use plugin
Plugin 'tpope/vim-fugitive'         "vi에서 git 사용
Plugin 'vim-airline/vim-airline'
Plugin 'scrooloose/nerdtree'
Plugin 'airblade/vim-gitgutter'
Plugin 'scrooloose/syntastic'
Plugin 'ctrlpvim/ctrlp.vim'
Plugin 'nanotech/jellybeans.vim'

call vundle#end()
filetype plugin indent on
"
" 간단한 도움말
" :PluginList       - 설정된 플러그인의 리스트
" :PluginInstall    - 플러그인 설치; 
"                     업데이트를 하려면 `!`를 덧붙이거나 :PluginUpdate 명령을> 사용하십시오
" :PluginSearch foo - Not Used
" :PluginClean      - 사용하지 않는 플러그인의 삭제를 확인; `!`를 붙여 자동 삭제를 승인하십시>   

" colorscheme jellybeans

set ruler
set expandtab

set nu
set ai
set nuw=5
set ts=4
set sol
set nocp
set sc
set autoindent
set wrap
set showmatch
set bs=2
set backspace=indent,eol,start
set hlsearch

syntax on
color jellybeans
set background=dark

set t_Co=256
set t_Sb=m
set t_Sf=m
let &t_ti.="\e[1 q"
let &t_SI.="\e[5 q"
let &t_EI.="\e[1 q"
let &t_te.="\e[0 q"
