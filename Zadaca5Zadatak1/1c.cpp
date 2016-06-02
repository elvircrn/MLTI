(V((x, (E((y, H(x, y)))) ^ (V((y, !(P(x, y)))))))) v (V (x, !G(x) v A(x)))
(V(x, (E((y, H(x, y)))) ^ (V((y, !(P(x, y))))))) v (V (x, !G(x) v A(x))) //x <-> z
(V(x, (E((y, H(x, y)))) ^ (V((y, !(P(x, y))))))) v (V (z, !G(z) v A(z)))
V(x, (E((y, H(x, y))) ^ V(y, !P(x, y)))) v (V (z, !G(z) v A(z))) // x <-> k
V(k, (E((y, H(k, y))) ^ V(y, !P(k, y)))) v (V (z, !G(z) v A(z)))
V(k, (E(y, H(k, y)) ^ V(y, !P(k, y)))) v (V (z, !G(z) v A(z))) // y <-> l
V(k, (E(y, H(k, y)) ^ V(l, !P(k, l)))) v (V (z, !G(z) v A(z)))
Vk Ey Vl Vz (H (k, y) ^ !P(k, l) v !G(z) v A(z))
