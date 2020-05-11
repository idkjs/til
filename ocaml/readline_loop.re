let () = {
  let b = ref(false);
  while (! b^) {
    print_string("(y/n): ");
    let str = read_line();
    print_endline(str);
    if (str.[0] == 'y') {
      b := true;
    };
  };
};
