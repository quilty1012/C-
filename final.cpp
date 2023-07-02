#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//date object
struct getTimes
{
   int nowyear;
   int nowmonth;
   int nowday;
   int afteryear;
   int aftermonth;
   int afterday;
};

//the end of apply interval,to check the end of interval is apply or not
struct checkapply
{
	int afteryear;
	int aftermonth;
	int afterday;
};

//to sort the start of date interval
bool comparenow(const getTimes &d1, const getTimes &d2)
{  		   				
	if (d1.nowyear < d2.nowyear)
		return true;
	if (d1.nowyear == d2.nowyear && d1.nowmonth < d2.nowmonth)
		return true;
	if (d1.nowyear == d2.nowyear && d1.nowmonth == d2.nowmonth 		   && d1.nowday < d2.nowday)
		return true;

	return false;
}

bool comparepubliend(const getTimes &d1, const getTimes &d2)
{
    if (d1.nowyear < d2.afteryear)
        return true;
    if (d1.nowyear == d2.afteryear && d1.nowmonth < d2.aftermonth)
        return true;
    if (d1.nowyear == d2.afteryear && d1.nowmonth == d2.aftermonth   && d1.nowday < d2.afterday)
        return true;
	if (d1.nowyear == d2.afteryear && d1.nowmonth == d2.aftermonth   && d1.nowday == d2.afterday)
		return true;
    return false;
}



//calculate the differences days of one date object
int diffday(struct getTimes times)
{
	int nowyear,nowmonth,afteryear,aftermonth;
	
	nowyear=times.nowyear;
	nowmonth=times.nowmonth;
	afteryear=times.afteryear;
	aftermonth=times.aftermonth;
	if (nowmonth<=2)
	{
        nowmonth+=13;
		nowyear-=1;	
	}		
	else
        nowmonth+=1;

	if (aftermonth<=2)
	{
	    aftermonth+=13;
		afteryear-=1;
	}
	else
        aftermonth+=1;	

	int N1 = 1461*nowyear/4 + 153*nowmonth/5 + times.nowday;
	int N2 = 1461*afteryear/4 + 153*aftermonth/5 + times.afterday;

	int disDay;

	if(N1>N2)
		disDay = N1-N2;
	else
		disDay = N2-N1;

	return disDay;
}



bool isoverlap ( struct getTimes t1, struct getTimes t2 )
{
	int x,y;
	if (t1.nowyear < t2.afteryear)
        x=1;
	else if (t1.nowyear == t2.afteryear && t1.nowmonth < t2.aftermonth)
        x=1;
	else if (t1.nowyear == t2.afteryear && t1.nowmonth == t2.aftermonth && t1.nowday < t2.afterday)
        x=1;
	else if (t1.nowyear == t2.afteryear && t1.nowmonth == t2.aftermonth && t1.nowday == t2.afterday)
		x=1;
	else
		x=0;	

	
	if (t2.nowyear < t1.afteryear)
        y=1;
	else if (t2.nowyear == t1.afteryear && t2.nowmonth < t1.aftermonth)
        y=1;
    else if (t2.nowyear == t1.afteryear && t2.nowmonth == t1.aftermonth && t2.nowday < t1.afterday)
        y=1;
	else if (t2.nowyear == t1.afteryear && t2.nowmonth == t1.aftermonth && t2.nowday == t1.afterday)
		y=1;
    else
        y=0;

	return (x && y);	
}

bool ischeckapply(struct getTimes t , struct checkapply Checkapply)
{
	if (t.afteryear ==Checkapply.afteryear && t.aftermonth == Checkapply.aftermonth && t.afterday == Checkapply.afterday)
		return true;
	else
		return false;
}

struct getTimes minafter(struct getTimes t1, struct getTimes t2)
{
    if (t1.afteryear < t2.afteryear)
        return t1;
    else if (t1.afteryear == t2.afteryear && t1.aftermonth < t2.aftermonth)
        return t1;
    else if (t1.afteryear == t2.afteryear && t1.aftermonth == t2.aftermonth && t1.afterday < t2.afterday)
        return t1;
    else if (t1.afteryear == t2.afteryear && t1.aftermonth == t2.aftermonth && t1.afterday == t2.afterday)
        return t1;
    else
        return t2;
}	

struct getTimes maxnow(struct getTimes t1, struct getTimes t2)
{
    if (t1.nowyear < t2.nowyear)
        return t2;
    else if (t1.nowyear == t2.nowyear && t1.nowmonth < t2.nowmonth)
        return t2;
    else if (t1.nowyear == t2.nowyear && t1.nowmonth == t2.nowmonth && t1.nowday < t2.nowday)
        return t2;
    else if (t1.nowyear == t2.nowyear && t1.nowmonth == t2.nowmonth && t1.nowday == t2.nowday)
		return t2;
	else
		return t1;
}

struct getTimes maxafter(struct getTimes t1, struct getTimes t2)
{
    if (t1.afteryear < t2.afteryear)
        return t2;
    else if (t1.afteryear == t2.afteryear && t1.aftermonth < t2.aftermonth)
        return t2;
    else if (t1.afteryear == t2.afteryear && t1.aftermonth == t2.aftermonth && t1.afterday < t2.afterday)
        return t2;
    else if (t1.afteryear == t2.afteryear && t1.aftermonth == t2.aftermonth && t1.afterday == t2.afterday)
		return t2;
	else
		return t1;
}

struct getTimes minnow(struct getTimes t1, struct getTimes t2)
{
    if (t1.nowyear < t2.nowyear)
        return t1;
    else if (t1.nowyear == t2.nowyear && t1.nowmonth < t2.nowmonth)
        return t1;
    else if (t1.nowyear == t2.nowyear && t1.nowmonth == t2.nowmonth && t1.nowday < t2.nowday)
        return t1;
    else if (t1.nowyear == t2.nowyear && t1.nowmonth == t2.nowmonth && t1.nowday == t2.nowday)
        return t1;
    else
        return t2;
}

bool equalnow(struct getTimes t1,struct getTimes t2)
{
	if (t1.nowyear == t2.nowyear && t1.nowmonth == t2.nowmonth && t1.nowday == t2.nowday)
		return true;
	else
		return false;
}

bool equalafter(struct getTimes t1,struct getTimes t2)
{
    if (t1.afteryear == t2.afteryear && t1.aftermonth == t2.aftermonth && t1.afterday == t2.afterday)
        return true;
    else
        return false;
}


int diffday(struct getTimes maxnow, struct getTimes minafter)
{   

    int nowyear,nowmonth,afteryear,aftermonth;
    
    nowyear=maxnow.nowyear;
    nowmonth=maxnow.nowmonth;
    afteryear=minafter.afteryear;
    aftermonth=minafter.aftermonth;

    if (nowmonth<=2)
    {   
        nowmonth+=13;
        nowyear-=1;
    }   
    else
        nowmonth+=1;
    
    if (aftermonth<=2)
    {   
        aftermonth+=13;
        afteryear-=1;
    }
    else
        aftermonth+=1;
    
    int N1 = 1461*nowyear/4 + 153*nowmonth/5 + maxnow.nowday;
    int N2 = 1461*afteryear/4 + 153*aftermonth/5 + minafter.afterday;
    
    int disDay;
    
    if(N1>N2)
        disDay = N1-N2;
    else
        disDay = N2-N1;
    
    return disDay;
}


int diffdaynow(struct getTimes nb, struct getTimes maxnow)
{

    int nowyear,nowmonth,afteryear,aftermonth,nowday,afterday;

    nowyear=nb.nowyear;
    nowmonth=nb.nowmonth;
	nowday=nb.nowday;
    afteryear=maxnow.nowyear;
    aftermonth=maxnow.nowmonth;
	afterday=maxnow.nowday;

    if (nowmonth<=2)
    {
        nowmonth+=13;
        nowyear-=1;
    }
    else
        nowmonth+=1;

    if (aftermonth<=2)
    {
        aftermonth+=13;
        afteryear-=1;
    }
    else
        aftermonth+=1;

    int N1 = 1461*nowyear/4 + 153*nowmonth/5 + nowday;
    int N2 = 1461*afteryear/4 + 153*aftermonth/5 + afterday;

    int disDay;

    if(N1>N2)
        disDay = N1-N2;
    else
        disDay = N2-N1;

    return disDay;
}

int countnbfunc (struct getTimes merge, vector<getTimes> &ve)
{
	int nbinterval;
	nbinterval=diffday(merge)+1;

	vector<int> vnb(nbinterval);

	bool isnbdone=true;
	int nu=0;
	int esize = static_cast<int>(ve.size());
    int endnbe = esize-1;
	int countnb=0;

	while(isnbdone)
    {
		bool Isnbeoverlap=isoverlap(merge,ve[nu]);

		if(Isnbeoverlap)
		{
			int x1,x2;
            struct getTimes T1,T2;
            T1=maxnow(merge,ve[nu]);
            T2=minafter(merge,ve[nu]);

            if(equalnow(merge,T1))
                x1=0;
            else
                x1=diffdaynow(merge,T1);

            if(equalafter(merge,T2))
                x2=nbinterval-1;
            else
                x2=diffday(merge,T2);

			for(int a=x1 ; a <= x2 ; a++ )
            {
                 if(vnb[a] == 0)
                     vnb[a] = 1;
            }

            cout << "overlap interval between non-behavior and exam is " << T1.nowyear - 1911 << "/" << T1.nowmonth << "/" << T1.nowday << ":" << T2.afteryear - 1911 <<"/"<<T2.aftermonth <<"/"<<T2.afterday <<", there is "<< x2 - x1 +1 << " days" << endl;

		}

        if(nu == endnbe)
        {
            isnbdone = false;
        }
        else
        {
            isnbdone = true;
            nu+=1;
        }
    }

	vector <int>::iterator vnbit;
    vector <int>::iterator vnbitend=vnb.end()-1;
	for(vnbit=vnb.begin();vnbit !=vnb.end();vnbit++)
    {
    	if((*vnbit) == 0 )
        {
            countnb +=1;

            if(vnbit == vnb.begin())
			{
				countnb -=1;

				cout << merge.nowyear - 1911 << "/" << merge.nowmonth << "/" << merge.nowday << " is the start of non-behavior , there is no overlap between non-behavior and exam" << endl;

			}

            if(vnbit == vnbitend)
			{
				countnb -=1;
			
				cout << merge.afteryear - 1911 << "/" << merge.aftermonth << "/" << merge.afterday << " is the end of non-behavior , there is no overlap between non-behavior and exam" << endl;

			}
        }
    }
	
	cout << "non-behavior interval is " << countnb << " days" << endl;	

	return countnb;

}



int main()
{
	vector <getTimes> vg;
    struct getTimes date1,date2;
    int mingnow1,mingafter1,mingnow2,mingafter2;

	struct getTimes Publi;
	int ming;
	cout <<"publication date(yyy/mm/dd):" << endl;
    scanf("%d/%d/%d",&ming , &Publi.nowmonth , &Publi.nowday);
    Publi.nowyear=ming + 1911;



    cout <<"apply_start(yyy/mm/dd):" << endl;
    scanf("%d/%d/%d",&mingnow1 , &date1.nowmonth , &date1.nowday);
	date1.nowyear=mingnow1 + 1911;
    cout << "apply_end(yyy/mm/dd):" << endl;
    scanf("%d/%d/%d",&mingafter1 , &date1.aftermonth , &date1.afterday);
    date1.afteryear=mingafter1 + 1911;

	struct checkapply Checkapply;
	Checkapply.afteryear=date1.afteryear;
	Checkapply.aftermonth=date1.aftermonth;
	Checkapply.afterday=date1.afterday;

	
	if( comparenow( date1 , Publi ) && comparepubliend( Publi, date1 ) )
	{
		date1.nowyear=Publi.nowyear;
		date1.nowmonth=Publi.nowmonth;
		date1.nowday=Publi.nowday;

		int applyinterval=diffday(date1);
    	cout << "apply interval is " << applyinterval <<" days"<< endl;

		vg.push_back(date1);
	}
	else if(!comparepubliend( Publi, date1 ))
	{
		cout << "publication date is after the end of apply interval " << endl;
		vg.push_back(date1);
	}
	else
	{
		int applyinterval=diffday(date1);
		cout << "apply interval is " << applyinterval <<" days"<< endl;

		vg.push_back(date1);
	}

	bool checkinput=true;
	while(checkinput)
	{
		cout << "exam_start(yyy/mm/dd):" << endl;
		scanf("%d/%d/%d",&mingnow2 , &date2.nowmonth , &date2.nowday);
		date2.nowyear=mingnow2 + 1911;
		cout << "exam_end(yyy/mm/dd):" << endl;
		scanf("%d/%d/%d",&mingafter2 , &date2.aftermonth , &date2.afterday);
		date2.afteryear=mingafter2 + 1911;

		
		if( comparenow( date2 , Publi ) && comparepubliend( Publi, date2 ) )
    	{
        	date2.nowyear=Publi.nowyear;
        	date2.nowmonth=Publi.nowmonth;
        	date2.nowday=Publi.nowday;

			cout << "exam interval is "<< diffday(date2) + 1 <<" days" << endl;
			vg.push_back(date2);
    	}
    	else if(!comparepubliend( Publi, date2 ))
		{
        	cout << "publication date is after the end of exam interval" << endl; 
			vg.push_back(date2);
		}
		else
		{
			cout << "exam interval is "<< diffday(date2) + 1 <<" days" << endl;
			vg.push_back(date2);
		}
			
		char iscontinue;
		cout << "continue input or not(y/n):" << endl ;
		scanf(" %c",&iscontinue);

		if(iscontinue == 'y')
			checkinput=true;
		else
			checkinput=false;
	}
   //create the vector of exam 
	vector<getTimes> ve;

	vector<getTimes>::iterator it;
	it=vg.begin()+1;

	ve.assign(it,vg.end());

	sort(vg.begin(),vg.end(),comparenow);
	sort(ve.begin(),ve.end(),comparenow);

	int totaldateday=0;

	vector <getTimes>::iterator viter;
	for(viter=vg.begin();viter !=vg.end();viter++)
	{
		cout << (*viter).nowyear - 1911 <<"/"<< (*viter).nowmonth<<"/"<<(*viter).nowday<< ":" << (*viter).afteryear - 1911 <<"/"<<(*viter).aftermonth <<"/"<<(*viter).afterday << endl;
	
		totaldateday=totaldateday + diffday(*viter) + 1 ;

	}

	cout << "total date interval is " << totaldateday << " days" << endl;

	int x=0;

	struct getTimes Tempt;
	Tempt.nowyear=vg[x].nowyear;
	Tempt.nowmonth=vg[x].nowmonth;
	Tempt.nowday=vg[x].nowday;
	Tempt.afteryear=vg[x].afteryear;
	Tempt.aftermonth=vg[x].aftermonth;
	Tempt.afterday=vg[x].afterday;

	int totaloverlapday=0;
	
	bool isdone=true;
	int checkapplycondi;
	int size = static_cast<int>(vg.size());

	while(isdone)
	{
		bool Isoverlap=isoverlap(Tempt,vg[x+1]);
		int overlapday=0;
		if(Isoverlap)
		{
			struct getTimes T1,T2;
			T1=maxnow(Tempt,vg[x+1]);
			T2=minafter(Tempt,vg[x+1]);
			
			overlapday=diffday( T1, T2)+1;
			
			cout <<"overlap interval is "<< T1.nowyear-1911 <<"/"<<T1.nowmonth<<"/"<<T1.nowday<<"-"<<T2.afteryear-1911<<"/"<<T2.aftermonth<<"/"<<T2.afterday<<", there is "<<overlapday <<" days" <<endl;

			totaloverlapday += overlapday;
	
		}
		else
		{
			totaloverlapday += overlapday;
			
			if(ischeckapply(Tempt,Checkapply))
				checkapplycondi=1;

		}

		struct getTimes adjust;
		adjust=maxafter(Tempt,vg[x+1]);

		Tempt.nowyear=vg[x+1].nowyear;
    	Tempt.nowmonth=vg[x+1].nowmonth;
    	Tempt.nowday=vg[x+1].nowday;
    	Tempt.afteryear=adjust.afteryear;
    	Tempt.aftermonth=adjust.aftermonth;
    	Tempt.afterday=adjust.afterday;

		
		int end=x+2;

		if( end == size)
		{
			isdone = false;
			
			struct getTimes T3;
			T3=maxafter(Tempt,vg[x+1]);	
			if(ischeckapply(T3,Checkapply) || checkapplycondi == 1 )
			{
				checkapplycondi = 1;

				cout << Checkapply.afteryear - 1911 << "/" << Checkapply.aftermonth << "/" << Checkapply.afterday << " is the end of apply , there is no overlap between apply and exam " << endl;
			}
			else
				checkapplycondi = 0;

		}			
		else
		{
			isdone = true;
			x+=1;
		}
	}
	cout << "total overlap interval is " << totaloverlapday << " days" << endl;

	int expandday;

	if(checkapplycondi == 1)
		expandday=totaldateday - totaloverlapday -  1;
	else
		expandday=totaldateday - totaloverlapday;

	cout << "expanding interval is " << expandday << " days" << endl; 

// calculate nonbehavior	
	vector <getTimes> vn;
	cout <<"nonbehavior1_start(yyy/mm/dd):" << endl;
    scanf("%d/%d/%d",&mingnow1 , &date1.nowmonth , &date1.nowday);
    date1.nowyear=mingnow1 + 1911;
    cout <<"nonbehavior1_end(yyy/mm/dd):" << endl;
    scanf("%d/%d/%d",&mingafter1 , &date1.aftermonth , &date1.afterday);
    date1.afteryear=mingafter1 + 1911;
	
	int nonbehavior1=diffday(date1);
	cout << "nonbehavior1 interval is " << nonbehavior1 - 1 <<" days"<< endl;

	vn.push_back(date1);
	
	cout << "nonbehavior2_start(yyy/mm/dd):" << endl;
    scanf("%d/%d/%d",&mingnow2 , &date2.nowmonth , &date2.nowday);
    date2.nowyear=mingnow2 + 1911;
    cout << "nonbehavior2_end(yyy/mm/dd):" << endl;
    scanf("%d/%d/%d",&mingafter2 , &date2.aftermonth , &date2.afterday);
    date2.afteryear=mingafter2 + 1911;

    int nonbehavior2=diffday(date2);
    cout << "nonbehavior2 interval is "<< nonbehavior2 - 1 <<" days" << endl;

	vn.push_back(date2);

	sort(vn.begin(),vn.end(),comparenow);

	cout << "exam interval : " << endl;
	for(viter=ve.begin();viter !=ve.end();viter++)
    {
        cout << (*viter).nowyear - 1911 <<"/"<< (*viter).nowmonth<<"/"<<(*viter).nowday<< ":" << (*viter).afteryear - 1911 <<"/"<<(*viter).aftermonth <<"/"<<(*viter).afterday << endl;

    }

	cout << "non-behavior interval : " << endl;

	for(viter=vn.begin();viter !=vn.end();viter++)
    {        cout << (*viter).nowyear - 1911 <<"/"<< (*viter).nowmonth<<"/"<<(*viter).nowday<< ":" << (*viter).afteryear - 1911 <<"/"<<(*viter).aftermonth <<"/"<<(*viter).afterday << endl;

    }

	bool Isnboverlap=isoverlap(vn[0],vn[1]);
	int countnb;
	int countnb1;
	int countnb2;
	struct getTimes merge;
	if(Isnboverlap)
	{
		struct getTimes TT1,TT2;
		TT1=minnow(vn[0],vn[1]);
		TT2=maxafter(vn[0],vn[1]);
		
		merge.nowyear=TT1.nowyear;
		merge.nowmonth=TT1.nowmonth;
		merge.nowday=TT1.nowday;
		merge.afteryear=TT2.afteryear;
		merge.aftermonth=TT2.aftermonth;
		merge.afterday=TT2.afterday;

		cout << "there is overlap interval between two non-behavior interval " << endl;

		countnb=countnbfunc( merge, ve );

	}
	else
	{
		countnb1=countnbfunc( vn[0], ve );
		countnb2=countnbfunc( vn[1], ve );

		countnb = countnb1 + countnb2 ;

		cout << "total non-behavior interval is " << countnb << " days" << endl;
	}

	int expanddaynb = expandday - countnb ;


	cout << "while substracts non-behavior interval, expanding interval is " << expanddaynb << " days" << endl;



    system("PAUSE");
    
    return 0;
}

