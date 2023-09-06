#include <bits/stdc++.h>

using namespace std;

///***********///
///Information
///***********///

///********************
///area_triangle(a,b,c)
///This function return the area of the a triangle, this function receive three parameter, this parameter
///are the three side of the triangle, and return a double with the area of the triangle. This function
///use of formula of Heron.

void area_triangle()
{
    string bas;
    cout << '\n' << "Insert the side size of the triangle: ";
    long double a, b, c;
    cin >> a >> b >> c;
    getline(cin,bas);
    cout << '\n' << "The triangle area is: ";
    long double P = (a + b + c)/2;
    cout << sqrt(P*(P-a)*(P-b)*(P-c)) << '\n' << '\n';
    return;
}

void area_triangleHELP()
{
    cout << '\n' << "This function return the area of the a triangle, this function receive three";
    cout << '\n' << "parameters, this parameters are the three side of the triangle, and return a";
    cout << '\n' << "double with the area of the triangle. This function use of formula of Heron.";
    cout << '\n';
    return;
}

///*****************
///eq_squared(a,b,c)
///Solve a equation squared the form ax²+bx+c, this function receive the parameter 'a', 'b' and 'c'.
///Return a vector<double>, the first value point if have solve or not, if the value is '0' not have
///solve in the real number, if is '1' have one solve or twos in the real number. The value second and
///third are the value of the variable x1 y x2.
///Ex: vector<double> Eq; Eq[0] = 1(have solve), Eq[1] = 12(value of x1), Eq[2] = 3(value of x2);

void eq_squared()
{
    string bas;
    double a, b, c;
    cout << '\n' << "Insert the parameter 'a', 'b' and 'c' of the equation: ";
    cin >> a >> b >> c;
    getline(cin,bas);
    int D = b*b-4*a*c;
    vector<double> Eq(2);
    if(D<0)
    {
        cout << '\n' << "The equation not have solve in the real number." << '\n' << '\n';
        return;
    }
    if(!D)
    {
        Eq[0] = -b/(2*a);
        cout << '\n' << "The equation have only one solve in the real number: " << Eq[0] << '\n' << '\n';
        return;
    }
    Eq[0] = (-b-sqrt(D))/(2*a);
    Eq[1] = (-b+sqrt(D))/(2*a);
    cout << '\n' << "The equation have two solves in the real number: " << Eq[0] << " " << Eq[1] << '\n' << '\n';
    return;
}

void eq_squaredHELP()
{
    cout << '\n' << "Solve a equation squared the form ax^2 + bx + c, this function receive the";
    cout << '\n' << "parameters 'a', 'b' and 'c'. Return if have solve or not and if have one";
    cout << '\n' << "solve or twos solves in the real number. The values first and second are the";
    cout << '\n' << "values of the variables x1 y x2.";
    cout << '\n';
    return;
}

///*****************************
///ruffini(vector<int>,(bool),e)
///This function receive of first parameter a vector that have the numbers of the polynomial orderly
///of form ax³+bx²+cx+d in where the vector is like that vector[]={a,b,c,d}; is perform a division
///synthetic of a polynomial between a binomial if the second parameter is '1'. The third parameter
///is use if is perform the value of division synthetic, this value is the binomial (x-e), if
///not is perform a division this value is omit. If is a division synthetic this function return a
///vector<double> with the result in order ascending of form ax³+bx²+cx+d, ex: vector[]={a,b,c,d}, the
///last value point the rest of the division synthetic; if is a factory the function  return a vector
///in this the first value point if this polynomial have solve or not, if have return '1' if not
///return '0', the second value is 'n' the quotient of form (x-n), the rest is the result of
///the factory. Ex: vector[0] = 1(have solve), vector[1] = 4(quotient x - 4), vector[2...n]={a,b,c,d};
///The vector have that to be of a size more than one.

void ruffini()
{
    string bas;
    int N;
    vector<int> ruff;
    bool b;
    int div = 0;

    cout << '\n' << "Insert the size of polynomial: ";

    cin >> N;

    cout << '\n' << "Insert the number of polynomial of form orderly: ";

    for(int i = 0 ; i < N ; i++)
    {
        int n;
        cin >> n;
        ruff.push_back(n);
    }

    cout << '\n' << "Division synthetic('1') or factory a polynomial('0'): ";

    cin >> b;

    vector<int> result(ruff.size()+2);
    if(b)
    {
        cout << '\n' << "Insert the value 'e' of division synthetic of form (x-e): ";
        cin >> div;
        getline(cin,bas);

        result[0]=ruff[0];
        for(int i = 1; i < ruff.size(); i++)
            result[i] = result[i-1]*div+ruff[i];

        cout << '\n' << "The result of the division synthetic of the polynomial between the binomial is:" << '\n' << '\n';

        for(int i = 0 ; i < N - 1 ; i++)
        {
            cout << result[i] << " ";
        }

        cout << '\n' << '\n' << "The rest of the division is: " << result[N-1] << '\n' << '\n';

        int cont = N - 2;

        cout << "quotient: ";

        cout << "(";

        if(result[0] < 0)
        {
            cout << "-";
        }

        for(int i = 0 ; i < N - 2 ; i++)
        {
            if(result[i])
            {
                if(abs(result[i]) == 1)
                {
                    if(cont > 1)
                    {
                        cout << "x^" << cont;
                    }
                    else
                    {
                        cout << "x";
                    }
                }
                else
                {
                    if(cont > 1)
                    {
                        cout << abs(result[i]) << "x^" << cont;
                    }
                    else
                    {
                        cout << abs(result[i]) << "x";
                    }

                }

            }

            if(result[i+1] < 0)
            {
                cout << " - ";
            }
            else if(result[i+1] > 0)
            {
                cout << " + ";
            }

            cont--;
        }

        cout << abs(result[N-2]) << ")";

        cout << '\n' << '\n';

        return;
    }
    else
    {
        getline(cin,bas);

        result[2]=ruff[0];
        vector<int>dt;
        for(int i = 1 ; i <= abs(ruff.back())/2; i++)
        {
            if(!(ruff.back()%i))
            {
                dt.push_back(-i);
                dt.push_back(i);
            }
        }
        dt.push_back(-ruff.back());
        dt.push_back(ruff.back());
        for(int d = 0; d < dt.size(); d++)
        {
            for(int i = 1; i < ruff.size(); i++)
                result[i+2] = result[i+1]*dt[d]+ruff[i];
            if(!(result.back()))
            {
                result[0]=1;
                result[1]=dt[d];
                break;
            }
        }

        if(!result[0])
        {
            cout << '\n' <<"This polynomial not have solve with ruffini method." << '\n' << '\n';
        }
        else
        {

            cout << '\n' << "The quotient 'n' of form (x-n) is: " << result[1] << '\n';

            cout << '\n' << "The rest of the result of the factory of the polynomial in order descending is:" << '\n' << '\n';

            for(int i = 2 ; i <= N ; i++)
            {
                cout << result[i] << " ";
            }

            cout << '\n' << '\n';

            cout << "fact: ";

            int cont = N - 2;

            if(result[1] > 0)
            {
                cout << "(x - " << abs(result[1]) <<") (";
            }
            else
            {
                cout << "(x + " << abs(result[1]) <<") (";
            }

            if(result[2] < 0)
            {
                cout << "-";
            }

            for(int i = 2 ; i < N ; i++)
            {
                if(result[i])
                {
                    if(abs(result[i]) == 1)
                    {
                        if(cont > 1)
                        {
                            cout << "x^" << cont;
                        }
                        else
                        {
                            cout << "x";
                        }
                    }
                    else
                    {
                        if(cont > 1)
                        {
                            cout << abs(result[i]) << "x^" << cont;
                        }
                        else
                        {
                            cout << abs(result[i]) << "x";
                        }

                    }

                }

                if(result[i+1] < 0)
                {
                    cout << " - ";
                }
                else if(result[i+1] > 0)
                {
                    cout << " + ";
                }

                cont--;
            }

            cout << abs(result[N]) << ")";

            cout << '\n' << '\n';

        }

        return;
    }
}

void ruffiniHELP()
{
    cout << '\n' << "This function receive of first parameter a number N that point the size of";
    cout << '\n' << "the polynomial to factory, next the N numbers of the polynomial orderly of";
    cout << '\n' << "form ax^3 + bx^2 + cx + d; is perform a division synthetic of a polynomial";
    cout << '\n' << "between a binomial if the second parameter is '1'. The third parameter is";
    cout << '\n' << "use if is perform the value of division synthetic, this value is the";
    cout << '\n' << "binomial (x-e), if not is perform a division this value is omit. If is a";
    cout << '\n' << "division synthetic this function return a joint the number with the result";
    cout << '\n' << "in order ascending of form ax^3 + bx^2 + cx + d.";
    cout << '\n';
    return;
}

///************************
///not_angle("raz_t",angle)
///This function receive the first parameter a string that point the type the trigonometry rate
///"sin", "cos", "tan", "cot", "csc" and "sec". The second parameter receive a int that is a notable
///angle. This function return a string that point the result of the function in form simple and
///easy for calculating. Ex: ("sen",45) = "sqrt(2)/2". In case of not to be a notable angle return
///"N/S". Ex:("sen",25) = "N/S". Remember that the notable angle are 30º, 45º and 60º. Also this
///function can receive axis angle Ex: 0º, 90º, 180º, 270º and 360º. The angle receive can to be
///more than 360º. Ex 390º = 30º, 390º % 360º = 30º. If the first parameter is incorrect return "N/S";
///if the trigonometry rate not is define return N/I/D

void not_angle()
{
    string bas;
    string razt;
    int angle;

    cout << '\n' << "Insert the trigonometry rate to calculate: ";
    cin >> razt;
    cout << '\n' << "Insert the angle: ";
    cin >> angle;
    getline(cin,bas);

    map<string,map<int,string> > m;
    angle=abs(angle);
    string rt = razt;
    int ang = angle;
    angle%=360;
    if(angle > 90 && angle <= 180)
        angle = 180 - angle;
    else if(angle > 180 && angle <= 270)
        angle = angle - 180;
    else if(angle > 270 && angle <= 360)
        angle = 360 - angle;
    if(razt == "cos")
    {
        razt="sin";
        angle=90-angle;
    }
    else if(razt == "cot")
    {
        razt="tan";
        angle=90-angle;
    }
    else if(razt == "sec")
    {
        razt="csc";
        angle=90-angle;
    }
    m["sin"][0]="0";
    m["sin"][30]="1/2";
    m["sin"][45]="sqrt(2)/2";
    m["sin"][60]="sqrt(3)/2";
    m["sin"][90]="1";
    m["tan"][0]="0";
    m["tan"][30]="sqrt(3)/3";
    m["tan"][45]="1";
    m["tan"][60]="sqrt(3)";
    m["tan"][90]="N/I/D";
    m["csc"][0]="N/I/D";
    m["csc"][30]="2";
    m["csc"][45]="sqrt(2)";
    m["csc"][60]="[2*sqrt(3)]/3";
    m["csc"][90]="1";
    if(!m[razt][angle].size())
    {
        cout << '\n' <<"N/S" << '\n' << '\n';
        return;
    }
    string result;
    if(m[razt][angle]!="0")
    {
        if(rt == "sin" || rt == "csc")
        {
            if(sin(M_PI/180*ang) < 0)result = "-";
        }
        else if(rt == "cos" || rt == "sec")
        {
            if(cos(M_PI/180*ang) < 0)result = "-";
        }
        else if(rt == "tan" || rt == "cot")
            if(tan(M_PI/180*ang) < 0)result = "-";
    }

    result+=m[razt][angle];
    cout << '\n' << "The result is: " << result << '\n' << '\n';
    return;
}

void not_angleHELP()
{
    cout << '\n' << "This function receive the first parameter a string that point the type the";
    cout << '\n' << "trigonometry rate \"sin\", \"cos\", \"tan\", \"cot\", \"csc\" and \"sec\".";
    cout << '\n' << "The second parameter receive a int that is a notable angle. This function";
    cout << '\n' << "return a string that point the result of the function in form simple and easy";
    cout << '\n' << "for calculating. Ex: (\"sen\",45) = \"sqrt(2)/2\". In case of not to be a";
    cout << '\n' << "notable angle return \"N/S\". Ex:(\"sen\",25) = \"N/S\". Remember that the";
    cout << '\n' << "notable angle are 30, 45 and 60. Also this function can receive axis angle";
    cout << '\n' << "Ex: 0, 90, 180, 270 and 360. The angle receive can to be more than 360.";
    cout << '\n' << "Ex 390 = 30, 390 % 360 = 30. If the first parameter is incorrect return";
    cout << '\n' << "\"N/S\"; if the trigonometry rate not is define return N/I/D";
    cout << '\n';
}

///****************************
///sol_triangle(vector<double>)
///This function receive a vector<double> organize of the following form (side_1,opposite_angle_1).
///Ex: vector[] = {side1,opp_ang1,side2,opp_ang2,side3,opp_ang3}. This function need at least three
///element Ex: (2-ang,side),(3-side),(2-side,ang). For point that not have a element put a zero.
///Ex: vector[] = {5,0,6,0,0,30}. This function return a vector<double> with the complete space.
///In case of not have solve return a vector with all the space with the value zero. The side in
///the vector can not to be negative because return a vector with zeros. The angle can to be negative
///and bigger than 360º. The angle have that to add 180º.

void sol_triangle()
{
    string bas;
    vector<double> t(6);

    cout << '\n' << "Insert the sides and the opposites angles: ";

    for(int i = 0 ; i < 6 ; i++)
    {
        cin >> t[i];
    }

    getline(cin,bas);

    int side = 0;
    int angle = 0;
    double sum = 0;
    bool b = 0;
    for(int i = 0; i < 6; i+=2)
        if(t[i])side++;
    for(int i = 1; i < 6; i+=2)
        if(t[i])angle++;
    for(int i = 1; i < 6; i+=2)
    {
        t[i]=fmod(t[i],360);
        if(t[i]<0)t[i]+=360;
    }
    for(int i = 0; i < 6; i+=2)
        if(t[i]<0)
        {
            b=1;
            break;
        }
    if(angle == 3)
        for(int i = 1; i < 6; i+=2)
            sum+=t[i];
    if(sum != 180 && angle == 3)b=1;
    if(!side || side+angle<3 || b)
    {
        cout << '\n' <<"This triangle not have solve. The dates are insufficient or incorrect." << '\n' << '\n';
        return;
    }
    if(t[1]&&t[3])t[5]=180-t[3]-t[1];
    else if(t[3]&&t[5])t[1]=180-t[5]-t[3];
    else if(t[5]&&t[1])t[3]=180-t[5]-t[1];
    for(int i = 0; i < 6; i+=2)
        if(t[i]&&t[i+1])
        {
            b=1;
            break;
        }
    if(b)
    {
        if(((t[0]&&t[1])&&(t[2]||t[3]))||((t[0]||t[1])&&(t[2]&&t[3])))
        {
            if(!t[0])t[0]=t[2]/sin(M_PI/180*t[3])*sin(M_PI/180*t[1]);
            else if(!t[1])
            {
                t[1]=asin(t[0]/t[2]*sin(M_PI/180*t[3]))*(180/M_PI);
                if(t[1]<0)t[1]+=180;
            }
            else if(!t[2])t[2]=t[0]/sin(M_PI/180*t[1])*sin(M_PI/180*t[3]);
            else if(!t[3])
            {
                t[3]=asin(t[2]/t[0]*sin(M_PI/180*t[1]))*(180/M_PI);
                if(t[3]<0)t[3]+=180;
            }
        }
        if(((t[2]&&t[3])&&(t[4]||t[5]))||((t[2]||t[3])&&(t[4]&&t[5])))
        {
            if(!t[2])t[2]=t[4]/sin(M_PI/180*t[5])*sin(M_PI/180*t[3]);
            else if(!t[3])
            {
                t[3]=asin(t[2]/t[4]*sin(M_PI/180*t[5]))*(180/M_PI);
                if(t[3]<0)t[3]+=180;
            }
            else if(!t[4])t[4]=t[2]/sin(M_PI/180*t[3])*sin(M_PI/180*t[5]);
            else if(!t[5])
            {
                t[5]=asin(t[4]/t[2]*sin(M_PI/180*t[3]))*(180/M_PI);
                if(t[5]<0)t[5]+=180;
            }
        }
        if(((t[4]&&t[5])&&(t[0]||t[1]))||((t[4]||t[5])&&(t[0]&&t[1])))
        {
            if(!t[4])t[4]=t[0]/sin(M_PI/180*t[1])*sin(M_PI/180*t[5]);
            else if(!t[5])
            {
                t[5]=asin(t[4]/t[0]*sin(M_PI/180*t[1]))*(180/M_PI);
                if(t[5]<0)t[5]+=180;
            }
            else if(!t[0])t[9]=t[4]/sin(M_PI/180*t[5])*sin(M_PI/180*t[1]);
            else if(!t[1])
            {
                t[1]=asin(t[0]/t[4]*sin(M_PI/180*t[5]))*(180/M_PI);
                if(t[1]<0)t[1]+=180;
            }
        }
        if(t[1]&&t[3])t[5]=180-t[3]-t[1];
        else if(t[3]&&t[5])t[1]=180-t[5]-t[3];
        else if(t[5]&&t[1])t[3]=180-t[5]-t[1];
        if(((t[0]&&t[1])&&(t[2]||t[3]))||((t[0]||t[1])&&(t[2]&&t[3])))
        {
            if(!t[0])t[0]=t[2]/sin(M_PI/180*t[3])*sin(M_PI/180*t[1]);
            else if(!t[1])
            {
                t[1]=asin(t[0]/t[2]*sin(M_PI/180*t[3]))*(180/M_PI);
                if(t[1]<0)t[1]+=180;
            }
            else if(!t[2])t[2]=t[0]/sin(M_PI/180*t[1])*sin(M_PI/180*t[3]);
            else if(!t[3])
            {
                t[3]=asin(t[2]/t[0]*sin(M_PI/180*t[1]))*(180/M_PI);
                if(t[3]<0)t[3]+=180;
            }
        }
        if(((t[2]&&t[3])&&(t[4]||t[5]))||((t[2]||t[3])&&(t[4]&&t[5])))
        {
            if(!t[2])t[2]=t[4]/sin(M_PI/180*t[5])*sin(M_PI/180*t[3]);
            else if(!t[3])
            {
                t[3]=asin(t[2]/t[4]*sin(M_PI/180*t[5]))*(180/M_PI);
                if(t[3]<0)t[3]+=180;
            }
            else if(!t[4])t[4]=t[2]/sin(M_PI/180*t[3])*sin(M_PI/180*t[5]);
            else if(!t[5])
            {
                t[5]=asin(t[4]/t[2]*sin(M_PI/180*t[3]))*(180/M_PI);
                if(t[5]<0)t[5]+=180;
            }
        }
        if(((t[4]&&t[5])&&(t[0]||t[1]))||((t[4]||t[5])&&(t[0]&&t[1])))
        {
            if(!t[4])t[4]=t[0]/sin(M_PI/180*t[1])*sin(M_PI/180*t[5]);
            else if(!t[5])
            {
                t[5]=asin(t[4]/t[0]*sin(M_PI/180*t[1]))*(180/M_PI);
                if(t[5]<0)t[5]+=180;
            }
            else if(!t[0])t[9]=t[4]/sin(M_PI/180*t[5])*sin(M_PI/180*t[1]);
            else if(!t[1])
            {
                t[1]=asin(t[0]/t[4]*sin(M_PI/180*t[5]))*(180/M_PI);
                if(t[1]<0)t[1]+=180;
            }
        }
    }
    else
    {
        side = 0;
        for(int i = 0; i < 6; i+=2)
            if(t[i])side++;
        if(side == 3)
        {
            t[1]=acos((t[2]*t[2]+t[4]*t[4]-t[0]*t[0])/(2*t[2]*t[4]))*(180/M_PI);
            if(t[1]<0)t[1]+=180;
            t[3]=acos((t[0]*t[0]+t[4]*t[4]-t[2]*t[2])/(2*t[0]*t[4]))*(180/M_PI);
            if(t[3]<0)t[3]+=180;
            t[5]=180-t[3]-t[1];
        }
        else
        {
            if(t[0]&&t[3]&&t[4])
                t[2]=sqrt(t[0]*t[0]+t[4]*t[4]-2*t[0]*t[4]*cos(M_PI/180*t[3]));
            else if(t[1]&&t[2]&&t[4])
                t[0]=sqrt(t[2]*t[2]+t[4]*t[4]-2*t[2]*t[4]*cos(M_PI/180*t[1]));
            else if(t[0]&&t[2]&&t[5])
                t[4]=sqrt(t[0]*t[0]+t[2]*t[2]-2*t[0]*t[2]*cos(M_PI/180*t[5]));
            if(t[1])
            {
                t[3]=acos((t[0]*t[0]+t[4]*t[4]-t[2]*t[2])/(2*t[0]*t[4]))*(180/M_PI);
                if(t[3]<0)t[3]+=180;
                t[5]=180-t[3]-t[1];
            }
            else if(t[3])
            {
                t[1]=acos((t[2]*t[2]+t[4]*t[4]-t[0]*t[0])/(2*t[2]*t[4]))*(180/M_PI);
                if(t[1]<0)t[1]+=180;
                t[5]=180-t[3]-t[1];
            }
            else if(t[5])
            {
                t[1]=acos((t[2]*t[2]+t[4]*t[4]-t[0]*t[0])/(2*t[2]*t[4]))*(180/M_PI);
                if(t[1]<0)t[1]+=180;
                t[3]=180-t[5]-t[1];
            }
        }
    }

    cout << '\n' << "The triangle solve is: ";

    for(int i = 0 ; i < 6 ; i++)
    {
        cout << t[i] << " ";
    }

    cout << '\n' << '\n';

    return;
}

void sol_triangleHELP()
{
    cout << '\n' << "This function receive a list of numbers organize of the following form";
    cout << '\n' << "(side_1,opposite_angle_1). Ex: list[] = {sd1,ang1,sd2,ang2,sd3,ang3}.";
    cout << '\n' << "This function need at least three element Ex: (2-ang,side),(3-side),";
    cout << '\n' << "(2-side,ang). For point that not have a element put a zero. Ex: list[] =";
    cout << '\n' << "{5,0,6,0,0,30}. This function return a list of number with the complete space.";
    cout << '\n' << "In case of not have solve return a list equal to the insert to beginning.";
    cout << '\n' << "The side in the list can not to be negative because return incorrect. The";
    cout << '\n' << "angle can to be negative and bigger than 360. The angle have that to add 180.";
    cout << '\n';
}

///**********************
///fact_polynomial(m,p,q)
///This function factory a polynomial(of three term) of the form mx²+px+q, this function receive
///that parameter three int that point to m, p and q of the form of the polynomial mx²+px+q. This
///function return a vector<int> that have the result of the factory of the following form
///vector[]={n1,n2,n3,n4}; where n1*n2=m, n3*n4=q, and n1*n4+n2*n3=p; the result of factory is
///then (n1x+n3)(n2x+n4). In case of not have solve this function return a vector with the space
///complete with zeros. In this function m, p and q have that to be different from zero.

void fact_polynomial()
{
    string bas;
    int m, p, q;

    cout << '\n' << "Insert the parameter 'm', 'p' and 'q' of the polynomial: ";

    cin >> m >> p >> q;

    getline(cin,bas);

    vector<int>result(4);
    vector<int>dm;
    vector<int>dq;
    for(int i = 1; i <= abs(m/2); i++)
    {
        if(!(m%i))
        {
            dm.push_back(i);
            dm.push_back(-i);
        }
    }
    dm.push_back(m);
    dm.push_back(-m);
    for(int i = 1; i <= abs(q/2); i++)
    {
        if(!(q%i))
        {
            dq.push_back(i);
            dq.push_back(-i);
        }
    }
    dq.push_back(q);
    dq.push_back(-q);
    if(fmod(sqrt(m),1)!=0)dm.resize(dm.size()/2);
    else dm.resize(dm.size()/2+1);
    for(int i = 0; i < dm.size(); i++)
        for(int j = 0; j < dq.size(); j++)
            if(dm[i]*(q/dq[j])+(m/dm[i])*dq[j]==p)
            {
                result[0]=dm[i];
                result[1]=dq[j];
                result[2]=m/dm[i];
                result[3]=q/dq[j];

                cout << '\n' << "The result of factory the polynomial is: " << '\n' << '\n';

                cout << "fact: ";

                cout << "(";

                if(result[0] == 1){
                    cout << "x";
                }
                else if(result[0] == -1){
                    cout << "-x";
                }
                else cout << result[0] << "x";

                if(result[1] > 0)
                {
                    cout << " + ";
                }
                else
                {
                    cout << " - ";
                }

                cout << abs(result[1]) << ")";

                cout << " (";

                if(result[2] == 1){
                    cout << "x";
                }
                else if(result[2] == -1){
                    cout << "-x";
                }
                else cout << result[2] << "x";

                if(result[3] > 0)
                {
                    cout << " + ";
                }
                else
                {
                    cout << " - ";
                }

                cout << abs(result[3]) << ")";

                cout << '\n' << '\n';

                return;
            }

    cout << '\n' << "The polynomial not have solve." << '\n' << '\n';

    return;
}

void fact_polynomialHELP()
{
    cout << '\n' << "This function factory a polynomial(of three term) of the form mx^2 + px + q,";
    cout << '\n' << "this function receive that parameter three int that point to m, p and q of the";
    cout << '\n' << "form of the polynomial mx^2 + px + q. This function return a list that have the";
    cout << '\n' << "result of the factory of the following form list[]={n1,n2,n3,n4}; where n1*n2=m,";
    cout << "n3*n4=q, and n1*n4+n2*n3=p; the result of factory is then (n1x+n3)(n2x+n4).In";
    cout << '\n' << "this function m, p and q have that to be different from zero.";
    cout << '\n';
}
