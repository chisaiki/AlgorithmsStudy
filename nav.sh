# nav.sh — source this file, don't execute it: `source nav.sh`
# _ Marks a private helper function (not public function for usage)
_root() { 
    git rev-parse --show-toplevel; 
}

bst() {
    cd "$(_root)/Trees/Binary Trees/"
}

home() {
    cd "$(_root)"
}

# help is a builtin in bash (shows help for shell builtins) and zsh has similar. 
# This function will override it while sourced, 
# which means you lose access to the real help for that session.

navhelp(){
    echo "Available Shortcuts: "
    echo "home - takes you back to repo root"
    echo "bst - takes you to the binary search tree implementation"
}
