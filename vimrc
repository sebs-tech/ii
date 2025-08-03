" ii_runner.vim
" Description: Custom command to run /usr/local/bin/ii with optional flag
"              and paste its output into the current buffer.

" Define the path to your 'ii' executable.
" This path is fixed as per your request.
let s:ii_program_path = '/usr/local/bin/ii'

" Check if the 'ii' program exists and is executable.
" This helps provide a clear error message if the program isn't found.
if !executable(s:ii_program_path)
    echohl ErrorMsg
    echomsg "Error: 'ii' program not found or not executable at " . s:ii_program_path
    echohl None
    finish " Stop loading the script if the executable isn't there.
endif

" --- Helper function to run the 'ii' program and paste its output ---
" This function now accepts a variable number of arguments using '...'.
" Will check if an argument was actually passed using a:0.
function! s:RunIIProgramWithFlag(...)
    " Determine the flag. If no arguments were passed to the function (a:0 is 0),
    " then the flag is an empty string. Otherwise, it's the first argument (a:1).
    let l:flag = (a:0 > 0) ? a:1 : ""

    " Construct the full shell command.
    " If a flag is provided, append it, properly shell-escaped.
    " If no flag, just run the program name.
    let command = s:ii_program_path
    if !empty(l:flag)
        let command .= " " . shellescape(l:flag)
    endif

    echomsg "Executing: " . command

    " Capture the output of the command.
    " system() runs the command and returns its stdout.
    let output = system(command)

    " Check if the command executed successfully.
    if v:shell_error != 0
        echohl ErrorMsg
        echomsg "Command failed: " . command
        echomsg "Error output:"
        echomsg output
        echohl None
        return "Command failed" " Return an error indicator
    endif

    " Store the current mode to determine if we need to re-enter insert mode.
    let l:original_mode = mode()
    let l:re_enter_insert_mode = (l:original_mode ==# 'i' || l:original_mode ==# 'R' || l:original_mode ==# 'v')

    " If in insert mode, temporarily exit to normal mode to paste.
    if l:re_enter_insert_mode
        normal! <Esc> " Exit insert mode if currently in it
    endif

    " Put the output into a temporary register 'g'.
    let @g = output

    " Paste the content from register 'g' at the current cursor position.
    normal! "gP

    " If we exited insert mode, re-enter it.
    if l:re_enter_insert_mode
        startinsert! " Re-enter insert mode at the exact position we left it
    endif

    echomsg "Output pasted from " . command
endfunction

" --- Define the custom command :II ---
" The -nargs=? attribute means this command accepts zero or one argument.
" If no argument is provided, <f-args> will be an empty string, which the
" function will now correctly handle.
command! -nargs=? II call s:RunIIProgramWithFlag(<f-args>)

" Inform the user that the command is loaded.
" echomsg "Custom command :II loaded. Use :II <optional_flag> (e.g., :II or :II -c) to run and paste output."
