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
Plugin 'git://git.wincent.com/command-t.git'
Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
"Plugin 'vim-airline/vim-airline'
Plugin 'https://github.com/wenlongche/Trinity'
Plugin 'https://github.com/wenlongche/SrcExpl'
Plugin 'https://github.com/yegappan/taglist'
"Plugin 'airblade/vim-gitgutter'
"Plugin 'scrooloose/syntastic'
"Plugin 'ctrlpvim/ctrlp.vim'
Plugin 'nanotech/jellybeans.vim'

call vundle#end()
" filetype plugin indent on
"
" 간단한 도움말
" :PluginList       - 설정된 플러그인의 리스트
" :PluginInstall    - 플러그인 설치; 
"                     업데이트를 하려면 `!`를 덧붙이거나 :PluginUpdate 명령을> 사용하십시오
" :PluginSearch foo - Not Used
" :PluginClean      - 사용하지 않는 플러그인의 삭제를 확인; `!`를 붙여 자동 삭제를 승인하십시>   

" colorscheme jellybeans

"NERDTree ON 단축키를 "\nt"로 설정
"map <Leader>nt <ESC>:NERDTree<CR>
"let NERDTreeShowHidden=1
" let NERDTreeQuitOnOpen=1
"let g:ctrlp_custom_ignore = {
"  \ 'dir':  '\.git$\|vendor$',
"    \ 'file': '\v\.(exe|so|dll)$'
"\ }

filetype on

" nmap <F8> :SrcExplToggle<CR>            "F8 Key = SrcExpl Toggling
nmap <F8> :TrinityToggleAll<CR>            "F8 Key = SrcExpl Toggling
" // Set the height of Source Explorer window                                  "
let g:SrcExpl_winHeight = 8
" // Set 100 ms for refreshing the Source Explorer                             "
let g:SrcExpl_refreshTime = 100
" // Set "Enter" key to jump into the exact definition context                 "
let g:SrcExpl_jumpKey = "<ENTER>"
" // Set "Space" key for back from the definition context                      "
let g:SrcExpl_gobackKey = "<SPACE>" 
nmap <C-H> <C-W>h                           "왼쪽 창으로 이동
nmap <C-J> <C-W>j                           "아래 창으로 이동
nmap <C-K> <C-W>k                           "윗 창으로 이동
nmap <C-L> <C-W>l                           "오른쪽 창으로 이동

" 붙여넣기 설정
set paste
set mouse-=a
" 한글 입력 설정
set encoding=utf-8
set termencoding=utf-8

set ruler
set expandtab
" 상태바 표시를 항상한다
set laststatus=2 
set statusline=\ %<%l:%v\ [%P]%=%a\ %h%m%r\ %F\

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
