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
y(i)=fscanf(comport,'%d'); % “%d” tamsayý okuyacaðýmýz için kullanýldý. devir
fprintf('voltage=%d',y(i)); % seri porttan veri okuma komutu “fscanf”
z(i)=fscanf(comport,'%d');%akim
fprintf('  ldr=%d',z(i));

W = v*i;
w = (2*3.14*y)/60;
k = W/w;

fprintf('   sýcaklýk=%d\n',k(i));

plot(y,'r', "linewidth", 2); %kýrmýzý ve “2” çizgi kalýnlýðýnda
hold on %tüm grafikler ayný ekranda çizilebilsin diye kullanýldý.
plot(z,'b','linewidth', 2);%mavi ve “2” çizgi kalýnlýðýnda
plot(k,'g','linewidth', 2);%yeþil ve “2” çizgi kalýnlýðýnda
hold off
drawnow % gerçek zamanlý grafik çizimi yapýlabilmesi için kullanýldý.
end

fclose(comport);
delete(comport);