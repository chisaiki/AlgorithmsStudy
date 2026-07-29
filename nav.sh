# nav.sh — source this file, don't execute it: `source nav.sh`
# _ Marks a helper function
_root() { 
    git rev-parse --show-toplevel; 
}

bst() {
    cd "$(_root)/Trees/Binary Trees/"
}

home() {
    cd "$(_root)"
}

help(){
    echo "Available Shortcuts: "
    echo "home - takes you back to main branch"
    echo "bst - takes you to the binary search tree implementation"
}

