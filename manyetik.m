Ac= 16e-4;
Ag = 16e-4;
lc=15e-2;
g= 4e-4;
N = 400;
mu_o = 4*pi*1e-7;
Rg = g/(mu_o*Ag);
for i =1:51
        mu_r(i) = 50 + (9000-300)*(i-1)/50;
        Rc(i) = lc/(mu_r(i)*mu_o*Ac);
        R=Rg+Rc(i);
        L(i) = N*N/R;
end
subplot (2,1,1)
plot(mu_r, Rc, 'k', 'lineWidth',1.5)
xlabel('Cekirdek bagýl gecirgenligi')
ylabel('Cekirdegin reluktansý')
subplot(2,1,2)
plot(mu_r,L,'k','LineWidth',1.5)
xlabel('Cekirdek bagil gecirgenligi')
ylabel('Enduktans')