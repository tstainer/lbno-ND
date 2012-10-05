#! /usr/bin/env python

def options(opt):
    opt.load('compiler_c compiler_cxx python')

    opt.add_option('--with-cern-root-system', default=None,
        help="Also looks for the CERN Root System at the given path")
    
    # Default the prefix to ${PWD}/install
    prefix_option = opt.parser.get_option("--prefix")
    old_default, new_default = prefix_option.default, "install"
    opt.parser.set_default("prefix", new_default)
    prefix_option.help = prefix_option.help.replace(old_default, new_default)

def configure(conf):
    conf.load('compiler_c compiler_cxx python')

    # Find root
    root_cfg = "root-config"
    if conf.options.with_cern_root_system:
        root_cfg = pjoin(conf.options.with_cern_root_system, "bin/root-config")
    conf.check_cfg(path=root_cfg, package="", uselib_store="CERN_ROOT_SYSTEM",
                   args='--libs --glibs --cflags', mandatory=False)

    # Extra ROOT library dependencies
    conf.env.append_value("LIB_CERN_ROOT_SYSTEM", ["Geom", "EG"])
    # Don't need to set LD_LIBRARY_PATH to run our executables
    conf.env.append_value("RPATH", [conf.env.LIBPATH_CERN_ROOT_SYSTEM])
    
    # Look at build/config.log for further information
    conf.to_log("Final environment:")
    conf.to_log(conf.env)

def build(bld):
    bld.load('compiler_c compiler_cxx python')

    # Some additional includes
    incdirs = "TPC TAS ECAL HCAL Magnet MIND Cavity"
    # Additional include files needed to build on Ubuntu
    incdirs += " extra-root"
    
    N = bld.path.find_node
    includes = [N("include")]
    includes += [N("include/" + x) for x in incdirs.split()]

    bld.env.append_value("INCLUDES_INCLUDES", includes)

    # Build a C++ executable named "geometry" using all .cxx files below src/
    bld(features="cxx cxxprogram",
        target="geometry",
        source=bld.path.ant_glob("src/**/*.cxx"),
        use=["CERN_ROOT_SYSTEM", "INCLUDES"])
