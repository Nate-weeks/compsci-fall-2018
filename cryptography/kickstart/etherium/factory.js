import web3 from './web3';

import CampaignFactory from './build/CompaignFactory.json'

const instance = new web3.eth.Contract(
  JSON.parse(CampaignFactory.interface),
  '0xa677Ada4F8dd578E5088793a1bFAc7A47eC1CE23'
);

export default instance;
