let file_read = (filename): list(string) => {
  let ic = open_in(filename);
  let try_read = () =>
    try(Some(input_line(ic))) {
    | End_of_file => None
    };

  let rec iter = acc =>
    switch (try_read()) {
    | Some(s) => iter([s, ...acc])
    | None =>
      close_in_noerr(ic);
      List.rev(acc);
    };

  iter([]);
};

let file_write = (filename, string_list): unit => {
  let oc = open_out(filename);
  List.iter(line => Printf.fprintf(oc, "%s\n", line), string_list);
  close_out_noerr(oc);
};

let cp = (source, dest): unit => file_write(dest, file_read(source));

let () =
  if (Array.length(Sys.argv) - 1 != 2) {
    Printf.printf("cp [SOURCE] [DEST]\n");
    exit(1);
  } else {
    let source = Sys.argv[1];
    if (!Sys.file_exists(source)) {
      Printf.printf("Source file is not found\n");
      exit(2);
    } else {
      let dest = Sys.argv[2];
      if (!Sys.file_exists(dest)) {
        cp(source, dest);
      } else {
        print_string("Overwrite? (y/n): ");
        if (read_line() == "y") {
          cp(source, dest);
          exit(0);
        } else {
          exit(0);
        };
      };
    };
  };
