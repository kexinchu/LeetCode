
#!/usr/bin/bash
dir="zipf1.5_filtered2k"

if [ ! -d ${dir} ]; then
  mkdir ${dir}
fi

preHot="./LeetCode/zipf1.5_filtered2k.txt"
file_="./LeetCode/zipf1.5_filtered2k.txt"

smart_ip=130.127.133.199
xdns_ip=130.127.133.211

#prob=`echo "scale=4;1/64"|bc`
#echo $prob
# 预热
dnspyre -c 64 --duration 60s --server ${smart_ip} "@${preHot}"
dnspyre -c 64 --duration 60s --server ${xdns_ip} "@${preHot}"

CONCURRENCY=(1 2 4 8 16 32 64 96 128 160 192 256 288 320 352 384 416)

for conc in ${CONCURRENCY[@]};
do
#   prob=`echo "scale=4;1/${conc}"|bc`
#   echo $prob
   dnspyre -c $conc --duration 60s --server ${smart_ip} "@${file_}" > "./${dir}/smart_concurrency_${conc}.txt"
   dnspyre -c $conc --duration 60s --server ${xdns_ip} "@${file_}" > "./${dir}/xdns_concurrency_${conc}.txt"
done

