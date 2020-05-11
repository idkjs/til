let () = {
  /* procedual */
  let c = ref(true);
  let i = ref(0);
  while (c^) {
    Printf.printf("%d\n", i^);
    if (i > ref(10)) {
      c := false;
    } else {
      i := i^ + 1;
    };
  };
  for (i in 0 to 10) {
    Printf.printf("%d\n", i);
  };
};
