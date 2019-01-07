cp -R cleos/main.cpp ../eos/programs/cleos
cp -R eosio.system ../eos/contracts/
cd ../eos

eosio-cpp -I /home/eos/eos/contracts/ -I /home/eos/eos/build/contracts/ -I /root/opt/boost/include/ -o contracts/eosio.system/eosio.system.wasm contracts/eosio.system/eosio.system.cpp

./eosio_build.sh -s "CR"
sudo ./eosio_install.sh