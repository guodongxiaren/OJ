# Read from the file file.txt and output the tenth line to stdout.
i=1
IFS=$'\n'
while read line
do
    if [ $i -eq 10 ];then
    echo $line
    fi
    let i++
done < file.txt
