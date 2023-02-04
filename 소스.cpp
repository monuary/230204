#include<iostream>
using namespace std;
int error = 0;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = 0;
		if (price < 0 || num < 0)
		{
			cout << "�Ǹ��� ���� �Է��� �߸��Ǿ����ϴ�" << endl << endl;
			error++;
			exit;
		}
	}
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		if (numOfApples < num)
		{
			myMoney += numOfApples * APPLE_PRICE;
			numOfApples = 0;
			return num;
		}
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const	//const�� ���̴� ������ ShowSalesResult �Լ��� ��������� �ٲ� �� ���� �Ǿ���.
	{
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}
	int ApplePrice() const
	{
		return APPLE_PRICE;
	}
	int NumApple() const
	{
		return numOfApples;
	}
};

class FruitBuyer
{
	int myMoney;	//�ƹ� ���� ������ private
	int numOfApples;

public:
	void InitMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
		if (money < 0)
		{
			cout << "������ ���� �Է��� �߸��Ǿ����ϴ�" << endl << endl;
			error++;
			exit;
		}
	}
	void BuyApples(FruitSeller& seller, int money)
	{
		if (money < 0)
		{
			cout << "�������� �ŷ��� �߸��Ǿ����ϴ�" << endl << endl;
			error++;
			exit;
		}
		int AmountOfApples = money / seller.ApplePrice();
		if (AmountOfApples > seller.NumApple())
		{
			AmountOfApples = seller.NumApple();
		}
		int MoneyForBuy = seller.ApplePrice() * AmountOfApples;
		numOfApples += seller.SaleApples(MoneyForBuy);
		myMoney -= MoneyForBuy;
	}
	void ShowBuyResult() const
	{
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
};

int main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 20);
	FruitBuyer buyer;
	buyer.InitMembers(30000);
	buyer.BuyApples(seller, 15500);
	if (error > 0)
	{
		return 0;
	}

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();

	return 0;
}