main() {
    local n p1 p2 s1 s2 i
    read n

    p1=100
    p2=100
    
    for ((i=0; i<$n; ++i)); do
        read s1 s2

        if [ $s1 -lt $s2 ]; then
            let p1-=s2
        elif [ $s1 -gt $s2 ]; then
            let p2-=s1
        fi
    done

    echo $p1
    echo $p2
}

main
