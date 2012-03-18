#line 1 "API.pm"
"#line 1 \"API.pm\"\n"
"\n"
"BEGIN {\n"
"$INC{\"$_.pm\"} = 1 foreach qw(\n"
"API Network Channel User\n"
"GChat GChat::IRC GChat::IRC::Server\n"
"GChat::IRC::Channel GChat::IRC::User\n"
")\n"
"}\n"
"\n"
"package API;\n"
"\n"
"sub get_module {1\n"
"}\n"
"\n"
"package GChat;\n"
"\n"
"sub EAT_ALL () { Xchat::EAT_ALL }\n"
"\n"
"\n"
"sub print {\n"
"my (undef, $text) = (shift, shift);\n"
"return unless defined $text;\n"
"Xchat::Internal::print($text);\n"
"}\n"
"\n"
"\n"
"sub command {\n"
"shift;\n"
"Xchat::Interal::command(@_);\n"
"}\n"
"\n"
"package Command;\n"
"\n"
"\n"
"\n"
"sub on {\n"
"my (undef, $cmd, $code, %options) = @_;\n"
"my $module = API::get_module(caller) or return;\n"
"my $hook   = Xchat::Internal::hook_command(\n"
"$cmd,\n"
"Xchat::PRI_NORM,\n"
"sub { $code->(); Xchat::EAT_ALL(); },\n"
"$options{help},\n"
"$options{data}\n"
") or return;\n"
"GChat->print($hook);\n"
"}\n"
"\n"
"1\n"
