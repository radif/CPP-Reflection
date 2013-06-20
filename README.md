CPP-Reflection
==============

Reflection is not supported by current c++ standard, This examples demonstrates how to adopt reflection in your c++ code, particularly, string fromClass and classFromString. It relies on templates and a couple of short macros. The Factory functions are indexed in a map against the class string. The map is static, therefore is instantiated before int main() is given a chance to run. Making the reflection available right at the start without any setup code being required to run.
