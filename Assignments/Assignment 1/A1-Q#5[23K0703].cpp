#include <iostream>
#include <cmath>
#include <ctime>
#include <chrono>

using namespace std;

int today[3] = {19, 01, 25};

class BOGOCoupon
{
    string couponCode;
    int validFrom[3];  // first element date, second day, third year
    int validUntil[3]; // first element date, second day, third year
    string restaurantCode;

public:
    BOGOCoupon() {}

    BOGOCoupon(
        string couponCode,
        int validFrom[3],
        int validUntil[3],
        string restaurantCode)
    {
        this->couponCode = couponCode;
        this->restaurantCode = restaurantCode;

        for (int i = 0; i < 3; i++)
        {
            this->validFrom[i] = validFrom[i];
            this->validUntil[i] = validUntil[i];
        }
    }

    string get_restaurant_code()
    {
        return restaurantCode;
    }

    string get_coupon_code()
    {
        return couponCode;
    }

    bool is_valid()
    {

        int validFromDays = validFrom[0] + (validFrom[1] * 30) + (validFrom[2] * 30 * 12);
        int validUntilDays = validUntil[0] + (validUntil[1] * 30) + (validUntil[2] * 30 * 12);
        int todayDays = today[0] + (today[1] * 30) + (today[2] * 30 * 12);

        // check if today is after validFrom
        if (todayDays < validFromDays)
        {
            return false;
        }

        // check if today is after validUntil
        if (todayDays > validUntilDays)
        {
            return false;
        }
        return true;
    }
};

class Restaurant
{
    string name;
    string location;
    string code;
    string *menuList;
    int numMenuItems;
    float *priceList;
    string *validCouponCodesList;
    int numCouponCodes;

public:
    static int redeemedCouponsCount;
    Restaurant(string name, string location, string code, string menuList[], float priceList[], int numMenuItems, string validCouponCodesList[], int numCouponCodes)
    {

        this->name = name;
        this->location = location;
        this->code = code;

        this->numMenuItems = numMenuItems;
        this->menuList = new string[numMenuItems];
        for (int i = 0; i < numMenuItems; i++)
        {
            this->menuList[i] = menuList[i];
        }

        this->priceList = new float[numMenuItems];
        for (int i = 0; i < numMenuItems; i++)
        {
            this->priceList[i] = priceList[i];
        }

        this->numCouponCodes = numCouponCodes;
        this->validCouponCodesList = new string[numCouponCodes];
        for (int i = 0; i < numCouponCodes; i++)
        {
            this->validCouponCodesList[i] = validCouponCodesList[i];
        }
    }

    void displayMenu()
    {
        cout << "===================" << endl;
        cout << "        MENU" << endl;
        cout << "===================" << endl
             << endl;

        cout << "Items\tPrices" << endl;

        for (int i = 0; i < numMenuItems; i++)
        {
            cout << menuList[i] << "\t" << priceList[i] << endl;
        }
    }

    void applyDiscount()
    {
        cout << "===================" << endl;
        cout << "        MENU" << endl;
        cout << "===================" << endl
             << endl;

        cout << "Items\tPrices" << endl;

        for (int i = 0; i < numMenuItems; i++)
        {
            cout << menuList[i] << "\t" << (float)priceList[i] / 2 << endl;
        }
    }

    bool validCoupon(BOGOCoupon couponToCheck)
    {
        for (int i = 0; i < numCouponCodes; i++)
        {
            if (couponToCheck.get_coupon_code() == validCouponCodesList[i])
            {
                return true;
            }
        }

        return false;
    }

    string getCode()
    {
        return code;
    }

    float generateBill(int itemIndex)
    {
        return priceList[itemIndex];
    }

    float applyDiscount(float currentBill)
    {
        // Halving the price because the average total bill gets half in BOGO
        return currentBill / 2;
    }
};

class User
{
    string name;
    int age;
    string mobile_number;

    BOGOCoupon coupons_list[20];
    int coupons_top;

    BOGOCoupon redeemed_coupons_list[20];
    int redeemed_coupons_top;

public:
    User(string name, int age, string mobile_number)
    {
        this->name = name;
        this->age = age;
        this->mobile_number = mobile_number;

        coupons_top = -1;
        redeemed_coupons_top = -1;
    }

    void accumulate_coupon(BOGOCoupon coupon)
    {
        if (coupon.is_valid())
        {
            coupons_top++;
            coupons_list[coupons_top] = coupon;
        }
    }

    int has_valid_coupon(string restaurantCode)
    {
        for (int i = 0; i <= coupons_top; i++)
        {
            if (coupons_list[i].is_valid() && coupons_list[i].get_restaurant_code() == restaurantCode)
            {
                return i;
            }
        }

        return -1;
    }

    float redeem_coupon(int couponIndex, float currentBill, Restaurant restaurant)
    {
        cout << restaurant.validCoupon(coupons_list[couponIndex]) << endl;
        if (coupons_list[couponIndex].is_valid() && coupons_list[couponIndex].get_restaurant_code() == restaurant.getCode() && restaurant.validCoupon(coupons_list[couponIndex]))
        {
            Restaurant::redeemedCouponsCount++;

            // Putting current coupon in the redeemed list
            BOGOCoupon couponToMove = coupons_list[couponIndex];

            for (int i = couponIndex + 1; i <= coupons_top; i++)
            {
                coupons_list[i - 1] = coupons_list[i];
            }

            coupons_list[coupons_top] = BOGOCoupon();

            coupons_top--;

            redeemed_coupons_top++;
            redeemed_coupons_list[redeemed_coupons_top] = couponToMove;

            return (float)restaurant.applyDiscount(currentBill);
        }

        return (float)-1.0;
    }
};

int Restaurant::redeemedCouponsCount = 0;

int main()
{
    // Header
    cout << "\n\nStudent ID: 23K0703" << endl;
    cout << "Name: Sarim Ahmed" << endl
         << endl;

    string foodHavenMenuItems[5] = {
        "Sushi",
        "Pad",
        "Thai",
        "Mango",
        "Tango",
    };

    float foodHavenPricesList[5] = {
        10.0,
        20.0,
        30.0,
        40.0,
        50.0,
    };

    string foodHavenCoupons[5] = {
        "ABCS123421",
        "AB56785678",
        "ABCF23r2EF",
        "ABC65trrrt",
        "A234234123",
    };

    string bytesPixelMenuItems[3] = {
        "Binary Burger",
        "Quantum Quinoa",
        "Data Donuts",
    };

    float bytesPixelPricesList[3] = {
        10.0,
        40.0,
        50.0,
    };

    string bytesPixelCoupons[5] = {
        "ABCSDFEXEF",
        "ABCSXEadsF",
        "ABCF23dsdF",
        "ABCS2rrer2",
        "A234234XEF",
    };

    Restaurant restaurant1("Food Haven", "City Center", "FH", foodHavenMenuItems, foodHavenPricesList, 5, foodHavenCoupons, 5);
    Restaurant restaurant2("Bytes Pixel", "Cyber Street", "BP", bytesPixelMenuItems, bytesPixelPricesList, 3, bytesPixelCoupons, 5);

    restaurant1.displayMenu();

    User user1("Sarim", 20, "123456789");

    int coupon1FromDate[3] = {03, 01, 1};
    int coupon1ToDate[3] = {03, 01, 29};
    BOGOCoupon coupon1("ABCS123421", coupon1FromDate, coupon1ToDate, "FH");

    user1.accumulate_coupon(coupon1);

    int validCouponIndex = user1.has_valid_coupon("FH");

    float actualBill = restaurant1.generateBill(4);

    float discountedBill = user1.redeem_coupon(validCouponIndex, actualBill, restaurant1);

    cout << "\n[+] User 1's original bill was Rs." << actualBill << " and it became Rs." << discountedBill << " after discount.";
}