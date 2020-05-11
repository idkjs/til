open Core;

/* 内部状態を持ち回すのでtail recursionのほうが少し遅い */
let tail_rec = n => {
  let rec iter = n_ =>
    if (n_ == 1000) {
      ();
    } else {
      n := n^ + 1;
      iter(n_ + 1);
    };

  iter(0);
};

let () = {
  let n = ref(0);
  let time1 = Unix.gettimeofday();
  for (i in 0 to 1000) {
    n := n^ + 1;
  };
  let time2 = Unix.gettimeofday();
  printf("%.10f\n", time1 -. time2);
  let n = ref(0);
  let time1 = Unix.gettimeofday();
  tail_rec(n);
  let time2 = Unix.gettimeofday();
  printf("%.10f\n", time1 -. time2);
};
