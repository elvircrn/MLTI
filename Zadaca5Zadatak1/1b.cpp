((L(s(u)))=>(V((z,D(z))))) v !(E((x,L(x))))v!(V((x,(L(x))=>!((E((y,D(x,s(y)))))v(E((y,U(s(x),y))))))))
((L(s(u)))=>(V((z,D(z))))) v !(E((x,L(x))))v!(V((x,(L(x))=>!((E((y,D(x,s(y)))))v(E((y,U(s(x),y))))))))
((L(s(u)))=>(V((z,D(z))))) v !(E((x,L(x)))) v !(V((x,(L(x))=>!((E((y,D(x,s(y)))))v(E((y,U(s(x),y))))))))
Vz(L(s(u)) => D(z)) v Vx(!L(x)) v (E(x, !(L(x) => !((E((y,D(x,s(y))))) v (E(y, U (s(x), y)))))))
Vz(L(s(u)) => D(z)) v Vx(!L(x)) v E (x, !(L(x) => !((E((y,D(x,s(y))))) v (E(y, U (s(x), y))))))
Vz(L(s(u)) => D(z)) v Vx(!L(x)) v E (x, !(L(x) => (!(E((y,D(x,s(y))))) ^ !(E(y, U (s(x), y))))))
Vz(L(s(u)) => D(z)) v Vx(!L(x)) v E (x, !(L(x) => ((V((y,!D(x,s(y))))) ^ (V(y, !U (s(x), y))))))
Vz(L(s(u)) => D(z)) v Vx(!L(x)) v E (x, !(L(x) => ((V((y,!D(x,s(y))))) ^ (V(k, !U (s(x), k)))))) //y <-> k
Vz(L(s(u)) => D(z)) v Vx(!L(x)) v E (x, !(L(x) => (V(y,!D(x,s(y))) ^ (V(k, !U (s(x), k))))))
Vz(L(s(u)) => D(z)) v Vx(!L(x)) v E (x, !(L(x) => (Vk Vy (!D(x,s(y)) ^ !U (s(x), k)))))
Vz(L(s(u)) => D(z)) v Vx(!L(x)) v E(x, !(L(x) => (Vk Vy (!D(x,s(y)) ^ !U (s(x), k)))))
Vz(L(s(u)) => D(z)) v Vx(!L(x)) v E(x, (L(x) ^ !(Vk Vy (!D(x,s(y)) ^ !U (s(x), k)))))
Vz(L(s(u)) => D(z)) v Vx(!L(x)) v (Ex Ek Ey, L(x) ^ (D(x,s(y)) v U (s(x), k)))
Vz(L(s(u)) => D(z)) v Vl(!L(l)) v (Ex Ek Ey, L(x) ^ (D(x,s(y)) v U (s(x), k))) // x <-> l
Vz Vl Ex Ek Ey !L(s(u)) v D(z) v !L(l) v L(x) ^ (D(x,s(y)) v U (s(x), k)) // x <-> l














