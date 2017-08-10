#include "echmetqtengine.h"

#define VAR_BEGIN       0
#define CHAR_BEGIN     "x"


EchmetQtEngine::EchmetQtEngine()
    :mVar(VAR_BEGIN),
     mCharVar(CHAR_BEGIN)
{
    globalSettings();
}

EchmetQtEngine::EchmetQtEngine(double var)
    :mVar(var),
     mCharVar(CHAR_BEGIN)
{
    globalSettings();
}

EchmetQtEngine::EchmetQtEngine(double var, QString charVar)
    :mVar(var),
     mCharVar(charVar)
{
    globalSettings();
}

EchmetQtEngine::EchmetQtEngine(QString func)
{
    globalSettings();
    solve(func);
}

void EchmetQtEngine::setVar(double var)
{
   mEngine.globalObject().setProperty(mCharVar, mVar);
   this->mVar=var;
}

void EchmetQtEngine::setChar(QString charVar)
{
    this->mCharVar=charVar;
    mEngine.globalObject().setProperty(mCharVar, mVar);
}

void EchmetQtEngine::globalSettings(void)
{
    setVar(mVar);
    setChar(mCharVar);
    setGlobalEngine();
}

void EchmetQtEngine::solve(QString func)
{
     this->mRes=mEngine.evaluate(func);
}

void EchmetQtEngine::setFunc(QString func)
{
    this->mFunc=func;
    solve(func);
}

void EchmetQtEngine::registerFunction(QString name, double (*func)(double))
{
//    std::function<double(double)> QFunc=func;
//    mEngine.globalObject().setProperty(name, mEngine.newFunction(
//                                       [QFunc](QCon *cxt, QEng *eng)
//                                       {
//                                            return QFunc(cxt->argument(0).toNumber()) ;
//                                       }));




//    std::vector<int> vec(10);
//    for (size_t i=0; i<10; ++i) {
//        vec[i]=10-i;
//    }
//    std::sort(vec.begin(), vec.end(), [](int a, int b)
//                                      {
//                                          return (std::abs(a)<std::abs(b));
//                                      });

///*  1    */    static QVal QCos        (QCon * cxt, QEng *) {   return cos(cxt->argument(0).toNumber()); }
}

void EchmetQtEngine::registerFunction(QString name, double constant)
{
//    mEngine.globalObject().setProperty(name, mEngine.newFunction([constant](QCon *cxt, QEng *eng) {
//                                                                    return constant;
//                                                                }));
//    mEngine.globalObject().setProperty(name,
//                                       mEngine.newFunction
//                                       ( [constant](QScriptContext *, QScriptEngine *) mutable
//                                         {
//                                            return constant;
//                                         }
//                                       ));
}


//....V
//    EchmetQtEngine eng;
//    eng.registerFunction("sin", std::sin);

//....


void EchmetQtEngine::setGlobalEngine(void)
{
//    registerFunction("cos", std::cos);
    mEngine.globalObject().setProperty( "cos",              mEngine.newFunction( QCos              ));
    mEngine.globalObject().setProperty( "sin",              mEngine.newFunction( QSin              ));
    mEngine.globalObject().setProperty( "tan",              mEngine.newFunction( QTan              ));
    mEngine.globalObject().setProperty( "acos",             mEngine.newFunction( QAcos             ));
    mEngine.globalObject().setProperty( "asin",             mEngine.newFunction( QAsin             ));
    mEngine.globalObject().setProperty( "atan",             mEngine.newFunction( QAtan             ));
    mEngine.globalObject().setProperty( "atan2",            mEngine.newFunction( QAtan2            ));
    mEngine.globalObject().setProperty( "cosh",             mEngine.newFunction( QCosh             ));
    mEngine.globalObject().setProperty( "sinh",             mEngine.newFunction( QSinh             ));
    mEngine.globalObject().setProperty( "tanh",             mEngine.newFunction( QTanh             ));
    mEngine.globalObject().setProperty( "acosh",            mEngine.newFunction( QAcosh            ));
    mEngine.globalObject().setProperty( "asinh ",           mEngine.newFunction( QAsinh            ));
    mEngine.globalObject().setProperty( "atanh",            mEngine.newFunction( QAtanh            ));
    mEngine.globalObject().setProperty( "exp",              mEngine.newFunction( QExp              ));
//  mEngine.globalObject().setProperty( "frexp",            mEngine.newFunction( QFrexp            ));
    mEngine.globalObject().setProperty( "ldexp",            mEngine.newFunction( QLdexp            ));
    mEngine.globalObject().setProperty( "log",              mEngine.newFunction( QLog              ));
    mEngine.globalObject().setProperty( "log10",            mEngine.newFunction( QLog10            ));
//  mEngine.globalObject().setProperty( "modf",             mEngine.newFunction( QModf             ));
    mEngine.globalObject().setProperty( "exp2",             mEngine.newFunction( QExp2             ));
    mEngine.globalObject().setProperty( "expm1",            mEngine.newFunction( QExpm1            ));
//  mEngine.globalObject().setProperty( "ilogb",            mEngine.newFunction( QIlogb            ));
    mEngine.globalObject().setProperty( "log1p",            mEngine.newFunction( QLog1p            ));
    mEngine.globalObject().setProperty( "log2",             mEngine.newFunction( QLog2             ));
    mEngine.globalObject().setProperty( "logb",             mEngine.newFunction( QLogb             ));
    mEngine.globalObject().setProperty( "scalbn",           mEngine.newFunction( QScalbn           ));
    mEngine.globalObject().setProperty( "scalbln",          mEngine.newFunction( QScalbln          ));
    mEngine.globalObject().setProperty( "pow",              mEngine.newFunction( QPow              ));
    mEngine.globalObject().setProperty( "sqrt",             mEngine.newFunction( QSqrt             ));
    mEngine.globalObject().setProperty( "cbrt",             mEngine.newFunction( QCbrt             ));
    mEngine.globalObject().setProperty( "hypot",            mEngine.newFunction( QHypot            ));
    mEngine.globalObject().setProperty( "erf",              mEngine.newFunction( QErf              ));
    mEngine.globalObject().setProperty( "erfc",             mEngine.newFunction( QErfc             ));
//  mEngine.globalObject().setProperty( "tgamma",           mEngine.newFunction( QTgamma           ));
    mEngine.globalObject().setProperty( "lgamma",           mEngine.newFunction( QLgamma           ));
    mEngine.globalObject().setProperty( "ceil",             mEngine.newFunction( QCeil             ));
    mEngine.globalObject().setProperty( "floor",            mEngine.newFunction( QFloor            ));
    mEngine.globalObject().setProperty( "fmod",             mEngine.newFunction( QFmod             ));
    mEngine.globalObject().setProperty( "trunc",            mEngine.newFunction( QTrunc            ));
    mEngine.globalObject().setProperty( "round",            mEngine.newFunction( QRound            ));
//  mEngine.globalObject().setProperty( "lround",           mEngine.newFunction( QLround           ));
//  mEngine.globalObject().setProperty( "llround",          mEngine.newFunction( QLlround          ));
    mEngine.globalObject().setProperty( "rint",             mEngine.newFunction( QRint             ));
//  mEngine.globalObject().setProperty( "lrint",            mEngine.newFunction( QLrint            ));
//  mEngine.globalObject().setProperty( "llrint",           mEngine.newFunction( QLlrint           ));
    mEngine.globalObject().setProperty( "nearbyint",        mEngine.newFunction( QNearbyint        ));
    mEngine.globalObject().setProperty( "remainder",        mEngine.newFunction( QRemainder        ));
//  mEngine.globalObject().setProperty( "remquo",           mEngine.newFunction( QRemquo           ));
    mEngine.globalObject().setProperty( "copysign",         mEngine.newFunction( QCopysign         ));
    mEngine.globalObject().setProperty( "nan",              mEngine.newFunction( QNan              ));
    mEngine.globalObject().setProperty( "nextafter",        mEngine.newFunction( QNextafter        ));
    mEngine.globalObject().setProperty( "nexttoward",       mEngine.newFunction( QNexttoward       ));
    mEngine.globalObject().setProperty( "fdim",             mEngine.newFunction( QFdim             ));
    mEngine.globalObject().setProperty( "fmax",             mEngine.newFunction( QFmax             ));
    mEngine.globalObject().setProperty( "fmin",             mEngine.newFunction( QFmin             ));
    mEngine.globalObject().setProperty( "fabs",             mEngine.newFunction( QFabs             ));
    mEngine.globalObject().setProperty( "abs",              mEngine.newFunction( QAbs              ));
    mEngine.globalObject().setProperty( "fma",              mEngine.newFunction( QFma              ));
    mEngine.globalObject().setProperty( "fpclassify",       mEngine.newFunction( QFpclassify       ));
    mEngine.globalObject().setProperty( "isfinite",         mEngine.newFunction( QIsfinite         ));
    mEngine.globalObject().setProperty( "isinf",            mEngine.newFunction( QIsinf            ));
    mEngine.globalObject().setProperty( "isnan",            mEngine.newFunction( QIsnan            ));
    mEngine.globalObject().setProperty( "isnormal",         mEngine.newFunction( QIsnormal         ));
    mEngine.globalObject().setProperty( "signbit",          mEngine.newFunction( QSignbit          ));
    mEngine.globalObject().setProperty( "isgreater",        mEngine.newFunction( QIsgreater        ));
    mEngine.globalObject().setProperty( "isgreaterequal",   mEngine.newFunction( QIsgreaterequal   ));
    mEngine.globalObject().setProperty( "isless",           mEngine.newFunction( QIsless           ));
    mEngine.globalObject().setProperty( "islessequal",      mEngine.newFunction( QIslessequal      ));
    mEngine.globalObject().setProperty( "islessgreater",    mEngine.newFunction( QIslessgreater    ));
    mEngine.globalObject().setProperty( "isunordered",      mEngine.newFunction( QIsunordered      ));
    mEngine.globalObject().setProperty( "math_errhandling", mEngine.newFunction( QMath_errhandling ));
    mEngine.globalObject().setProperty( "INFINITY",         mEngine.newFunction( QINFINITY         ));
    mEngine.globalObject().setProperty( "NAN",              mEngine.newFunction( QNAN              ));
    mEngine.globalObject().setProperty( "HUGE_VAL ",        mEngine.newFunction( QHUGE_VAL         ));
    mEngine.globalObject().setProperty( "HUGE_VALF",        mEngine.newFunction( QHUGE_VALF        ));
    mEngine.globalObject().setProperty( "HUGE_VALL",        mEngine.newFunction( QHUGE_VALL        ));
    mEngine.globalObject().setProperty( "double_t",         mEngine.newFunction( QDouble_t         ));
    mEngine.globalObject().setProperty( "float_t",          mEngine.newFunction( QFloat_t          ));
}
