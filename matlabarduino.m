% #define ADC1 A0  //ADC1 analog 0 pinini temsil ediyor.
% #define ADC2 A1 //ADC2 analog 1 pinini temsil ediyor.
%https://guraysonugur.aku.edu.tr/2017/03/07/arduinodan-matlab-ile-seri-com-port-kullanarak-sensor-verilerini-okumak/
%void setup() {
%Serial.begin(115200);
%}

%void loop() {

%Serial.println(analogRead(ADC1));
%delay(100); // 100 ms duraklama yap.
%Serial.println(analogRead(ADC2));
%delay(100);

%}

clc;
clear;

comport = serial('COM3','BaudRate',115200);

fopen(comport);


for i=1:100
v=12;    
y(i)=fscanf(comport,'%d'); % �%d� tamsay� okuyaca��m�z i�in kullan�ld�. devir
fprintf('voltage=%d',y(i)); % seri porttan veri okuma komutu �fscanf�
z(i)=fscanf(comport,'%d');%akim
fprintf('  ldr=%d',z(i));

W = v*i;
w = (2*3.14*y)/60;
k = W/w;

fprintf('   s�cakl�k=%d\n',k(i));

plot(y,'r', "linewidth", 2); %k�rm�z� ve �2� �izgi kal�nl���nda
hold on %t�m grafikler ayn� ekranda �izilebilsin diye kullan�ld�.
plot(z,'b','linewidth', 2);%mavi ve �2� �izgi kal�nl���nda
plot(k,'g','linewidth', 2);%ye�il ve �2� �izgi kal�nl���nda
hold off
drawnow % ger�ek zamanl� grafik �izimi yap�labilmesi i�in kullan�ld�.
end

fclose(comport);
delete(comport);