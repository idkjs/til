open Core;

class person = {
  as self;
  val mutable first_name = "John";
  val mutable last_name = "Doe";
  pub set_first_name = x => first_name = x;
  pub set_last_name = x => last_name = x;
  pub get_fullname = sprintf("%s %s", first_name, last_name);
  pub get_first_name = first_name;
  pub get_last_name = last_name;
};

let () = {
  let john = new person;
  print_endline(john#get_fullname);

  let bob = new person;
  bob#set_first_name("Bob");
  bob#set_last_name("Dylan");
  print_endline(bob#get_fullname);

  let alice = new person;
  alice#set_first_name("Alice");
  alice#set_last_name("Liddell");
  print_endline(alice#get_fullname);
};
