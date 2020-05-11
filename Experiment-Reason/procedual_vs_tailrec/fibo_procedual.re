let procedual = n => {
  let n1 = ref(0);
  let n2 = ref(1);
  let acc = ref(0);
  if (n == 0) {
    0;
  } else {
    for (i in 1 to n) {
      acc := n1^ + n2^;
      n1 := n2^;
      n2 := acc^;
    };
    n1^;
  };
};

let () = Printf.printf("%d\n", procedual(100));
