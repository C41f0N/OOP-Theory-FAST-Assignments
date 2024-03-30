#include <iostream>

using namespace std;

class SecurityTool
{
protected:
    string securityLevel;
    int numOfDevices;
    float cost;

public:
    SecurityTool(
        string securityLevel,
        int numOfDevices,
        float cost)
    {
        if (securityLevel == "Low" || securityLevel == "Medium" || securityLevel == "High")
        {
            this->securityLevel = securityLevel;
        }

        if (cost <= 0)
            cost = 1;

        this->cost = cost;
    }

    bool performScan()
    {
        return false;
    }
};

class FirewallTool : public SecurityTool
{
    int ports[23];
    string protocols[6];

public:
    FirewallTool(
        string securityLevel,
        float cost,
        int numOfDevices)
        : SecurityTool(
              securityLevel,
              numOfDevices,
              cost)
    {
        generateList();
    }

    void generateList()
    {
        for (int i = 0; i < 23; i++)
        {
            ports[i] = i + 7 + 1;
        }

        protocols[0] = "HTTPS";
        protocols[1] = "FTP";
        protocols[2] = "UDP";
        protocols[3] = "ICMP";
        protocols[4] = "SSH";
        protocols[5] = "SNMP";
    }

    bool performScan(int trafficPort, string trafficProtocol)
    {
        bool validPort = false, validProtocol = false;

        if (securityLevel == "High")
        {
            // Checking if port is valid
            for (int i = 0; i < 23; i++)
            {
                if (ports[i] == trafficPort)
                {
                    validPort = true;
                    break;
                }
            }

            // Checking if protocol is valid
            for (int i = 0; i < 6; i++)
            {
                if (protocols[i] == trafficProtocol)
                {
                    validProtocol = true;
                    break;
                }
            }
        }
        else if (securityLevel == "Medium")
        {

            // Checking for listed ports
            for (int i = 0; i < 23; i++)
            {
                if (ports[i] == trafficPort)
                {
                    validPort = true;
                    break;
                }
            }
            if (!validPort)
            {
                // Checking for 2 extra ports
                for (int i = 1; i <= 2; i++)
                {
                    if ((ports[19] + i) == trafficPort)
                    {
                        validPort = true;
                        break;
                    }
                }
            }
            // Checking if protocol is valid
            for (int i = 0; i < 6; i++)
            {
                if (protocols[i] == trafficProtocol)
                {
                    validProtocol = true;
                    break;
                }
            }
        }
        else if (securityLevel == "Low")
        {
            // Checking for listed ports
            for (int i = 0; i < 23; i++)
            {
                if (ports[i] == trafficPort)
                {
                    validPort = true;
                    break;
                }
            }

            if (!validPort)
            {
                // Checking for 5 extra ports
                for (int i = 1; i <= 5; i++)
                {
                    if ((ports[19] + i) == trafficPort)
                    {
                        validPort = true;
                        break;
                    }
                }
            }

            // Checking if protocol is valid
            for (int i = 0; i < 6; i++)
            {
                if (protocols[i] == trafficProtocol)
                {
                    validProtocol = true;
                    break;
                }
            }

            if (!validProtocol)
            {
                validProtocol = trafficProtocol == "TCP" || trafficProtocol == "DNS";
            }
        }

        return validPort && validProtocol;
    }
};

int main()
{

    // Solution Header
    cout << "Name: Sarim Ahmed" << endl;
    cout << "ID: 23K0703" << endl
         << endl;

    FirewallTool firewallTool("Low", 13.0, 5);

    bool allowed = firewallTool.performScan(33, "HTTPS");

    if (allowed)
    {

        cout << "Connection Allowed" << endl;
    }
    else
    {
        cout << "Connection Blocked" << endl;
    }
}