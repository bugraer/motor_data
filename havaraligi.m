x= [0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0];
L= [1.4 1.13 0.89 0.76 0.67 0.63 0.60 0.58 0.565 0.555 0.55];
x_m =x*1.e-2;
L_H= L*1.e-3;
x_len= length(x_m);
x_max=x_m(x_len);
a=polyfit(x_m,L_H,4);
for i= 1:51
    x_fit(i) = x_max* (i-1)/50;
    L_fit(i) =a(1) * x_fit (i)^4 + a(2) * x_fit(i)^3 + a(3) * x_fit(i) ^2 + a(4) * x_fit(i) + a(5);
end
subplot(3,1,1)
plot(x_m,L_H,'k')
title('gercek')
xlabel('\itx(m)')
ylabel('\itL(H)')
subplot(3,1,2)
plot(x_fit,L_fit,'k')
title('Egri uydurma')
xlabel('\itx(m)')
ylabel('\itx(H)')

I=0.8;
for i= 1:51
    x_fit(i) = 0.001 + 0.012* (i-1)/50;
    F(i)=4*a(1)*x_fit(i)^2+2*a(3)*x_fit(i)+a(4);
end
subplot(3,1,3)
plot(x_fit,F,'k')
xlabel('\itx(m)')
ylabel('Kuvvet(N)')