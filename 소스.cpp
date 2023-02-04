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
			cout << "판매자 정보 입력이 잘못되었습니다" << endl << endl;
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
	void ShowSalesResult() const	//const를 붙이는 것으로 ShowSalesResult 함수가 멤버변수를 바꿀 수 없게 되었다.
	{
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
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
	int myMoney;	//아무 선언 없으면 private
	int numOfApples;

public:
	void InitMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
		if (money < 0)
		{
			cout << "구매자 정보 입력이 잘못되었습니다" << endl << endl;
			error++;
			exit;
		}
	}
	void BuyApples(FruitSeller& seller, int money)
	{
		if (money < 0)
		{
			cout << "구매자의 거래가 잘못되었습니다" << endl << endl;
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
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
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

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();

	return 0;
}