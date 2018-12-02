const HDWalletProvider = require('truffle-hdwallet-provider');
const Web3 = require('web3');
const {interface, bytecode} = require('./compile');

const provider = new HDWalletProvider(
  'robot april fatigue siren blade unfold normal minimum mercy series obvious bread',
  'https://rinkeby.infura.io/v3/9319195d62034106b0e7b86277444e17'
);
const web3 = new Web3(provider)

const deploy = async () => {
  const accounts = await web3.eth.getAccounts();

  console.log('attempting to deploy from account', accounts[0])

  const result = await new web3.eth.Contract(JSON.parse(interface))
    .deploy({data: '0x' + bytecode, arguments: ['hi there']})
    .send({gas: '1000000', from: accounts[0]});

  console.log('contract deployed to', result.options.address);
};
deploy()
