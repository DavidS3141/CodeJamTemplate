diff --git a/CodeJam/Main.cpp b/examples/2020/KS_B/B/Main.cpp
index fad3e96..53ccd24 100644
--- a/CodeJam/Main.cpp
+++ b/examples/2020/KS_B/B/Main.cpp
@@ -1025,11 +1025,23 @@ void init(){
     cin >> T;
 }
 
+ll N, D;
+v(ll) Xi;
+
 void readInput(){
+    cin >> N >> D;
+    Xi.resize(N);
+    forn(i, N) cin >> Xi[i];
 }
 
 // write to COMM_TYPE result
 void calcFunction() {
+    result = D;
+    forn(ii, N){
+        ll i = N-1-ii;
+        ll x = Xi[i];
+        result = (result/x)*x;
+    }
 }
 
 } // namespace task