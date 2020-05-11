/** read_file_all: string -> string **/
let read_file_all = (filename): string => {
  let ic = open_in(filename);
  let n = in_channel_length(ic);
  let s = Bytes.create(n);
  really_input(ic, s, 0, n);
  close_in(ic);
  Bytes.to_string(s);
};

/** read_file_lines: string -> string list **/

let read_file_lines = (filename): list(string) => {
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

let () = {
  Printf.printf("%s\n", "Returns string");
  Printf.printf("%s\n", read_file_all("hello.ml"));
  Printf.printf("%s\n", "Returns string list");
  List.iter(Printf.printf("%s\n"), read_file_lines("hello.ml"));
};
