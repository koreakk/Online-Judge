read a b

a=$(($a*10000000000))
r=$(($a/$b))
n=0

if [ ${#r} -gt 10 ]
then
    n=${r:0:1}
    r=${r:1}
fi

echo $n.$r
