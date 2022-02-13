echo "============="

args=$(./gen.py $1)
./rev.py $args
echo $args
instras=$(./push_swap $args)

num=$(echo "$instras" | wc -l)

echo "number of commands is $num"

echo "$instras" | ./checker_linux $args

#echo "$instras"
