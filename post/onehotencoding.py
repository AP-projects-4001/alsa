import geopy.distance
import pandas as pd;
from sklearn.linear_model import LinearRegression;
from geopy.geocoders import Nominatim
#********************GET LAT AND LONG*********************#
myState = input("what's your State ? ")
geolocator = Nominatim(user_agent="MyApp");
loc = input("Where to send the product :  ");
location_company = geolocator.geocode(myState);  
location = geolocator.geocode(loc);
lat = location.latitude;
long = location.longitude;
lat_company = location_company.latitude;
long_company = location_company.longitude;
#******************GET DISTACE******************************#
coords_1 = (lat,long)
coords_2 = (lat_company,long_company)
dist = geopy.distance.distance(coords_1, coords_2).km
#*************************PREDICT***************************#
mylist = []
gul = 0 ; albrz = 0 ; ardbil = 0 ; azrgh = 0 ; azrshrgh = 0 ; bshhr = 0 ; chramahal = 0;
esf = 0 ; fars = 0 ; ghzvin = 0 ; ghm = 0 ; golstn = 0 ; hamdn = 0 ; hrmz = 0 ; ilam = 0;
kerman = 0 ; kermsh = 0 ; khzstn = 0 ; khrsnj = 0 ; khrsnsh = 0 ; khrsnrz = 0 ; khg = 0;
krdstn = 0 ; lrstn = 0 ; mrkzi = 0 ; mzndrn = 0 ; smnm = 0 ; shrz = 0 ; sistn = 0 ; tehran = 0 ; yzd = 0 ; znj = 0; 
for i in range(1,35):
    mylist.append(1);
if(myState == "Guilan"):
    gul = 1;
elif(myState == 'alborz'):
    albrz = 1;    
elif(myState == 'ardebil'):
    ardbil = 1;
elif(myState == 'azarbayejangharbi'):
    azrgh = 1;
elif(myState == 'azarbayejansharghi'):
    azrshrgh = 1;
elif(myState == 'booshehr'):
    bshhr = 1;
elif(mylist == 'chaharmahal'):
    chramahal = 1;
elif(myState == 'esfahan'):
    esf = 1;
elif(myState == 'fars'):
    fars = 1;
elif(myState == "ghazvin"):
    ghzvin = 1;
elif(myState == "ghom"):
    ghm = 1;
elif(myState == "golestan"):
    golstn = 1;
elif(myState == "hamedan"):
    hamdn = 1;
elif(myState == "hormozgan"):
    hrmz = 1;
elif(myState == "ilam"):
    ilam = 1;
elif(myState == "kerman"):
    kerman = 1;
elif(myState == "kermanshah"):
    kermsh = 1;
elif(myState == "khoozestan"):
    khzstn = 1;
elif(myState == "khorasanjonoobi"):
    khrsnj = 1;
elif(myState == "khorasanrazavi"):
    khrsnrz = 1;
elif(myState == 'khorasanshomali'):
    khrsnsh = 1;
elif(myState == 'kohgiloye'):
    khg = 1;
elif(myState == 'kordestan'):
    krdstn = 1;
elif(myState == 'lorestan'):
    lrstn = 1;
elif(myState == 'markazi'):
    mrkzi = 1;
elif(myState == 'mazandaran'):
    mzndrn = 1;
elif(myState == 'semnan'):
    smnm = 1;
elif(myState == 'shiraz'):
    shrz = 1;
elif(myState == 'sistanvabaloochestan'):
    sistn = 1;
elif(myState == 'tehran'):
    tehran = 1;
elif(myState == 'yazd'):
    yzd = 1;
elif(myState == 'zanjzn'):
    znj = 1;                  
else:
    print('This state does not exist...!!!')
    exit();                                                                                                         
df = pd.read_csv('ali.csv');
df2 = pd.get_dummies(df.twon);
df3 = pd.concat([df,df2],axis='columns')
df4 = df3.drop(['twon'],axis = "columns")
Reg = LinearRegression();
all = df4.drop(['price'],axis='columns');
P = df4.price;
Reg.fit(all,P);
print(Reg.predict
([[dist,gul,albrz,ardbil,azrgh,azrshrgh
,bshhr,chramahal,esf,fars,ghzvin,ghm,golstn,hamdn,hrmz,ilam
,kerman,kermsh,khzstn,khrsnj,khrsnsh,khrsnrz,khg,krdstn,lrstn
,mrkzi,mzndrn,smnm,shrz,sistn,tehran,yzd,znj
]]))