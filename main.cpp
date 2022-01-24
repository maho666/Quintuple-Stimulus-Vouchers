#include <iostream>
#include <iomanip>
#include <array>


using namespace std;

int main()
{
    int good_price,pay_need,money=830;//////輸入的金額,打完折扣的金額,剩餘的金額
    int money_value[] = {100,50,10,5,1};//////面額
    int remain_amount[] = {5,5,5,5,5};////voucher剩下的數量
    int paid_amount[] = {0,0,0,0,0};/////voucher付出的數量
    int money_paid[] = {0,0,0,0,0};////付出的金額

    char type,member;////紙本or數位,會員

    cout << "*** Welcome to Quintuple Stimulus Vouchers System ***" << endl;
    do
    {
    int done = 0;/////沒付完錢為0,付完錢為1
    float discount_type=1,discount_member=1;//////voucher打的折數
    cout << "Please enter the good price: ";
    cin >> good_price;
        if(good_price == -1)
        {
            break;
        }
    cout << "Please enter the type of vouchers (d/p): ";
    cin >> type;
        if(type == 'd')
            {
            discount_type = 0.8;
            }
        else if(type == 'p')
            {
            discount_type=0.9;
            }
    if(type == 'd')
    {
    cout << "Are you a member of NCU Bank (y/n): ";
    cin >> member;
        if(member == 'y')
            {
            discount_member = 0.9;
            }
        else if(member == 'n')
            {
            discount_member = 1;
            }
    }
    pay_need = good_price*discount_type*discount_member;
    cout << "The price you need to pay: "<< pay_need <<endl;

    if(money >= pay_need)
    {
    int i=0;

        for(i=0;i<5;i++)
        {
            if(i==0)
            {
            paid_amount[i] = (pay_need/money_value[i]);
                if(paid_amount[i]>remain_amount[i])
                {
                  paid_amount[i] = remain_amount[i];
                  //cout << "1.出多少: "<<paid_amount[i]<<"    "<<money_value[i]<<endl;
                  money_paid[i] = paid_amount[i]*money_value[i];
                    continue;/////跳出去下一個for
                }
            money_paid[i] = paid_amount[i]*money_value[i];
                if(money_paid[i] == pay_need)
                {
                    done = 1;
                }

            }
            else{
            paid_amount[i] = ((pay_need-money_paid[i-1])/money_value[i]);
            //cout<<i<<"  remain_[i]:"<<remain_amount[i]<<"  paid_amount[i]: "<<paid_amount[i]<<endl;
            if(paid_amount[i]>remain_amount[i])
                    {
                        paid_amount[i] = remain_amount[i];
                        //cout<<i<<"  remain_[i]:"<<remain_amount[i]<<"  paid_amount[i]: "<<paid_amount[i]<<endl;
                        //cout << "2.出多少: "<<paid_amount[i]<<"    "<<money_value[i]<<endl;
                        money_paid[i] = paid_amount[i]*money_value[i]+money_paid[i-1];
                        //cout <<"i: "<<i<<"   money_paid[i]  "<<money_paid[i]<<endl;
                        continue;
                    }
            money_paid[i] = paid_amount[i]*money_value[i]+money_paid[i-1];
            //cout <<"i: "<<i<<"   money_paid[i]  "<<money_paid[i]<<endl;
            if(money_paid[i] == pay_need)
                {
                    done = 1;
                }
            }
        }
////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
int a;
int restore=0;/////將小的面額付出去的錢補回
    if(done != 1)
    {
        for(int i = 0;i < 5;i++)
        {
            remain_amount[i] = remain_amount[i]-paid_amount[i];
        }
        for(a=i-1 ;a>=0;a--)
        {
            if(remain_amount[a] <= 0)
            {
                continue;
            }
            if(money_paid[a]<pay_need)
            {
                remain_amount[a]--;
                paid_amount[a]++;
                for(int b=a+1;b<5;b++)
                {
                    remain_amount[b] = remain_amount[b]+paid_amount[b];
                    restore = restore+paid_amount[b]*money_value[b];
                    paid_amount[b] = 0;
                }
            money_paid[a] = money_paid[i-1]-restore+1*money_value[a];/////only add value a
            }
            if(money_paid[a]>pay_need)
            {
                break;
            }

        }
    }

//////////////////////////////////////////////////////////////////////////////////////////
        if(done != 1)
        {
        money = money - money_paid[a];
        }
        else{
        money = money - money_paid[4];
        }

        cout << "The payment is processed as follows:"<<endl;
        for(int a=0;a<5;a++)
        {
            if(paid_amount[a]>0)
            {
                if(a==0)
                {
                    cout << right<<setw(5)<<paid_amount[0]<<" $"<<right<<setw(4)<<  "100"<<" voucher"<<endl;
                }
                else if(a==1)
                {
                    cout << right<<setw(5)<<paid_amount[1]<<" $"<<right<<setw(4)<< " 50"<<" voucher"<<endl;
                }
                else if(a==2)
                {
                    cout << right<<setw(5)<<paid_amount[2]<<" $"<<right<<setw(4)<< " 10"<<" voucher"<<endl;
                }
                else if(a==3)
                {
                    cout << right<<setw(5)<<paid_amount[3]<<" $"<<right<<setw(4)<< " 5"<<" voucher"<<endl;
                }
                else if(a==4)
                {
                    cout << right<<setw(5)<<paid_amount[4]<<" $"<<right<<setw(4)<< " 1"<<" voucher"<<endl;
                }


            }
        }




        if(done == 1)
        {
        for(int i = 0;i < 5;i++)
        {
            remain_amount[i] = remain_amount[i]-paid_amount[i];
        }
        }
        if(remain_amount[0]>0||remain_amount[1]>0||remain_amount[2]>0||remain_amount[3]>0||remain_amount[4]>0)
        {
        cout << "The remaining vouchers are as follows:"<<endl;
        for(int a=0;a<5;a++)
        {
            if(remain_amount[a]>0)
            {
                if(a==0)
                {
                    cout << setw(5)<<remain_amount[0]<<" $"<<right<<setw(4)<<  "100"<<" voucher"<<endl;
                }
                else if(a==1)
                {
                    cout << setw(5)<<remain_amount[1]<<" $"<<right<<setw(4)<< " 50"<<" voucher"<<endl;
                }
                else if(a==2)
                {
                    cout << setw(5)<<remain_amount[2]<<" $"<<right<<setw(4)<< " 10"<<" voucher"<<endl;
                }
                else if(a==3)
                {
                    cout << setw(5)<<remain_amount[3]<<" $"<<right<<setw(4)<< " 5"<<" voucher"<<endl;
                }
                else if(a==4)
                {
                    cout << setw(5)<<remain_amount[4]<<" $"<<right<<setw(4)<< " 1"<<" voucher"<<endl;
                }
            }
        }
        cout << endl;
        }

        else if(remain_amount[0]==0&&remain_amount[1]==0&&remain_amount[2]==0&&remain_amount[3]==0&&remain_amount[4]==0)
        {
            cout << "You do not remain any voucher"<<endl;
            break;
        }


    }
    else
    {
        cout << "You don't have enough voucher to buy the good"<<endl;
        cout<<endl;
            }
    }while(good_price != -1&&(good_price = cin.get() != EOF));

    cout << "Bye~"<<endl;
    return 0;
}
