from asyncore import read
from dis import dis
import pandas as pd;
from sklearn import linear_model;
from geopy.geocoders import Nominatim
import mpu
#********************GET LAT AND LONG*********************#
tehran_lat =  35.6892523;#mokhtasat sherkat
tehran_long = 51.3896004;#mokhtasat sherkat
geolocator = Nominatim(user_agent="MyApp");
loc = input("Where to send the product :  ");
location = geolocator.geocode(loc);
lat = location.latitude;
long = location.longitude;
#******************GET DISTACE******************************#
dist = mpu.haversine_distance((tehran_lat,tehran_long),(lat,long));
#*************************PREDICT***************************#
df=pd.read_csv('ali.csv');
REG = linear_model.ARDRegression();
REG.fit(df[['dist']],df.price);
Price = REG.predict([[dist]])
x = Price;
print ('Product post money is = ',x);