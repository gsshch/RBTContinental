#include "AbstractionAPI.h"
#include <stdlib.h>
#include <cstring>
#include <cstdio>
#include <iostream>
#include "../inc/NetworkLib.h"
using namespace std;

int main()
{
    Net_API_config_t configuration; 
    strcpy(configuration.S_interface, "enp0s3");
    strcpy(configuration.S_DUT_HW_Address, "08:00:27:fd:55:27");//08:00:27:68:41:d5 wassim mac 
    strcpy(configuration.S_DUT_IP_Address, "192.168.20.244"); // 192.168.20.114 wassim ip
    strcpy(configuration.S_Tester_HW_Address, "08:00:27:cd:64:f1");
    strcpy(configuration.S_Tester_IP_Address, "192.168.20.83");
    Set_Network_Abstration_API_Config(configuration);
    Net_API_config_t currentconfig=Get_Network_Abstration_API_Config();
    cout<<"interface "<<currentconfig.S_interface<<endl;
    cout<<"dut mac "<<currentconfig.S_DUT_HW_Address<<endl;
    cout<<"dut ip "<<currentconfig.S_DUT_IP_Address<<endl;
    cout<<"tester mac "<<currentconfig.S_Tester_HW_Address<<endl;
    cout<<"tester ip "<<currentconfig.S_Tester_IP_Address<<endl;
    //EditICMPField(&ICMP_P,ICMP,ICMP_identifier,(void *)0xffee);

    ICMP_Option_Packet ICMP_OP_P = CreateICMPOption();
    EditICMPOptionField(&ICMP_OP_P,IP, IP_Offset, (void *)0b0010000000000000);
    ICMP_Option_Compute_checksum(&ICMP_OP_P);
    SendICMPOption(ICMP_OP_P);
}
