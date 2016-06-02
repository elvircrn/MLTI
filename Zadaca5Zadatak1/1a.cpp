!( V((x, (W(x)) => !((E ((y, X(x, p(y))))) v (E((y, K(p(x), y)))))))) => (V((x,(E((y, X(x, y))))^(V((y, !(H(x, y))))))))
E((x, !((W(x)) => !((E ((y, X(x, p(y))))) v (E((y, K(p(x), y)))))))) => (V((x,(E((y, X(x, y))))^(V((y, !(H(x, y))))))))
E((x, (!(W(x)) v !((E ((y, X(x, p(y))))) v (E((y, K(p(x), y))))))   )) => (V((x,(E((y, X(x, y))))^(V((y, !(H(x, y))))))))
E((x, (!(W(x)) v (!(E ((y, X(x, p(y))))) ^ !(E((y, K(p(x), y)))))   )   )) => (V((x,(E((y, X(x, y))))^(V((y, !(H(x, y))))))))
E((x, (!(W(x)) v ((V ((y, !X(x, p(y))))) ^ (V((y, !K(p(x), y)))))   )   )) => (V((x,(E((y, X(x, y))))^(V((y, !(H(x, y))))))))
E((x, (!(W(x)) v ((V ((y, !X(x, p(y)) ^ !K(p(x), y)))))   )   )) => (V((x,(E(y, X(x, y)))^(V(y, !(H(x, y)))))))
!E((x, (!(W(x)) v ((V ((y, !X(x, p(y)) ^ !K(p(x), y)))))   )   )) v (V((x,(E(y, X(x, y)))^(V((z, !(H(x, z))))))))
!E((x, (!(W(x)) v ((V ((y, !X(x, p(y)) ^ !K(p(x), y)))))   )   )) v (V(k,(E(y, X(k, y)))^(V((z, !(H(k, z)))))))
!E((x, (!(W(x)) v ((V ((y, !X(x, p(y)) ^ !K(p(x), y)))))   )   )) v (V(k,(E(y, X(k, y)))^(V(z, !H(k, z)))))
!E((x, (!W(x) v ((V (y, !X(x, p(y)) ^ !K(p(x), y))))   )   )) v (V(k,(E(y, X(k, y)))^(V(z, !H(k, z)))))
!E((x, (!W(x) v ((V (l, !X(x, p(l)) ^ !K(p(x), l))))   )   )) v (V(k,(E(y, X(k, y)))^(V(z, !H(k, z)))))
V(x, !(!W(x) v (V (l, !X(x, p(l)) ^ !K(p(x), l)))   )   ) v (V(k,(E(y, X(k, y)))^(V(z, !H(k, z)))))
V(x, (W(x) ^ !(V (l, !X(x, p(l)) ^ !K(p(x), l))))  ) v (V(k,(E(y, X(k, y)))^(V(z, !H(k, z)))))
V(x, (W(x) ^ (E (l, X(x, p(l)) v K(p(x), l))))  ) v (V(k,(E(y, X(k, y)))^(V(z, !H(k, z)))))
Vx El(W(x) ^ (X(x, p(l)) v K(p(x), l))) v (V(k,(E(y, X(k, y)))^(V(z, !H(k, z)))))
Vx El(W(x) ^ (X(x, p(l)) v K(p(x), l))) v (Vk Ey Vz (X(k, y) ^  !H(k, z)))
Vx El Vk Ey Vz (W(x) ^ (X(x, p(l)) v K(p(x), l)) v (X(k, y) ^  !H(k, z)))





















