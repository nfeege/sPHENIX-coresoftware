AUTOMAKE_OPTIONS = foreign

AM_CPPFLAGS = \
  -I$(includedir) \
  -I$(OFFLINE_MAIN)/include \
  -I`root-config --incdir`

libPrototype4_la_LDFLAGS = \
  -nodefaultlibs \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib \
  `root-config --libs`

lib_LTLIBRARIES = \
  libPrototype4.la

pkginclude_HEADERS = \
  RawTower_Prototype4.h \
  RawTower_Temperature.h \
  PROTOTYPE4_FEM.h

libPrototype4_la_SOURCES = \
  RawTower_Prototype4.cc \
  RawTower_Prototype4Dict.C \
  Prototype4DSTReader.cc \
  Prototype4DSTReaderDict.C \
  CaloUnpackPRDF.C \
  CaloUnpackPRDFDict.C \
  TempInfoUnpackPRDF.C \
  TempInfoUnpackPRDFDict.C \
  RunInfoUnpackPRDF.C \
  RunInfoUnpackPRDFDict.C \
  EventInfoSummary.C \
  EventInfoSummaryDict.C \
  CaloCalibration.C \
  CaloCalibrationDict.C \
  GenericUnpackPRDF.C \
  GenericUnpackPRDFDict.C \
  PROTOTYPE4_FEM.C \
  PROTOTYPE4_FEMDict.C \
  RawTower_Temperature.cc \
  RawTower_TemperatureDict.C

libPrototype4_la_LIBADD = \
  -lSubsysReco \
  -lphool \
  -lfun4all \
  -lcalo_util \
  -lphparameter

BUILT_SOURCES = \
  testexternals.C

noinst_PROGRAMS = \
  testexternals

testexternals_LDADD = \
  libPrototype4.la

testexternals.C:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

##############################################
# please add new classes in alphabetical order
# Rule for generating CINT dictionaries from class headers.
%Dict.C: %.h %LinkDef.h
	rootcint -f $@ @CINTDEFS@ -c $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $^

clean-local:
	rm -f *Dict*

testexternals_SOURCES = testexternals.C
