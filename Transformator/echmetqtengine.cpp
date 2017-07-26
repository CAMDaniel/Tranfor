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


void EchmetQtEngine::setGlobalEngine(void)
{
    /*  1    */ mEngine.globalObject().setProperty( "cos",              mEngine.newFunction( QCos              ));
    /*  2    */ mEngine.globalObject().setProperty( "sin",              mEngine.newFunction( QSin              ));
    /*  3    */ mEngine.globalObject().setProperty( "tan",              mEngine.newFunction( QTan              ));
    /*  4    */ mEngine.globalObject().setProperty( "acos",             mEngine.newFunction( QAcos             ));
    /*  6    */ mEngine.globalObject().setProperty( "asin",             mEngine.newFunction( QAsin             ));
    /*  7    */ mEngine.globalObject().setProperty( "atan",             mEngine.newFunction( QAtan             ));
    /*  8    */ mEngine.globalObject().setProperty( "atan2",            mEngine.newFunction( QAtan2            ));
    /*  9    */ mEngine.globalObject().setProperty( "cosh",             mEngine.newFunction( QCosh             ));
    /*  10   */ mEngine.globalObject().setProperty( "sinh",             mEngine.newFunction( QSinh             ));
    /*  11   */ mEngine.globalObject().setProperty( "tanh",             mEngine.newFunction( QTanh             ));
    /*  12   */ mEngine.globalObject().setProperty( "acosh",            mEngine.newFunction( QAcosh            ));
    /*  13   */ mEngine.globalObject().setProperty( "asinh ",           mEngine.newFunction( QAsinh            ));
    /*  14   */ mEngine.globalObject().setProperty( "atanh",            mEngine.newFunction( QAtanh            ));
    /*  15   */ mEngine.globalObject().setProperty( "exp",              mEngine.newFunction( QExp              ));
//  /*  16   */ mEngine.globalObject().setProperty( "frexp",            mEngine.newFunction( QFrexp            ));
    /*  17   */ mEngine.globalObject().setProperty( "ldexp",            mEngine.newFunction( QLdexp            ));
    /*  18   */ mEngine.globalObject().setProperty( "log",              mEngine.newFunction( QLog              ));
    /*  19   */ mEngine.globalObject().setProperty( "log10",            mEngine.newFunction( QLog10            ));
//  /*  20   */ mEngine.globalObject().setProperty( "modf",             mEngine.newFunction( QModf             ));
    /*  21   */ mEngine.globalObject().setProperty( "exp2",             mEngine.newFunction( QExp2             ));
    /*  22   */ mEngine.globalObject().setProperty( "expm1",            mEngine.newFunction( QExpm1            ));
//  /*  23   */ mEngine.globalObject().setProperty( "ilogb",            mEngine.newFunction( QIlogb            ));
    /*  24   */ mEngine.globalObject().setProperty( "log1p",            mEngine.newFunction( QLog1p            ));
    /*  25   */ mEngine.globalObject().setProperty( "log2",             mEngine.newFunction( QLog2             ));
    /*  26   */ mEngine.globalObject().setProperty( "logb",             mEngine.newFunction( QLogb             ));
    /*  27   */ mEngine.globalObject().setProperty( "scalbn",           mEngine.newFunction( QScalbn           ));
    /*  28   */ mEngine.globalObject().setProperty( "scalbln",          mEngine.newFunction( QScalbln          ));
    /*  29   */ mEngine.globalObject().setProperty( "pow",              mEngine.newFunction( QPow              ));
    /*  30   */ mEngine.globalObject().setProperty( "sqrt",             mEngine.newFunction( QSqrt             ));
    /*  31   */ mEngine.globalObject().setProperty( "cbrt",             mEngine.newFunction( QCbrt             ));
    /*  32   */ mEngine.globalObject().setProperty( "hypot",            mEngine.newFunction( QHypot            ));
    /*  33   */ mEngine.globalObject().setProperty( "erf",              mEngine.newFunction( QErf              ));
    /*  34   */ mEngine.globalObject().setProperty( "erfc",             mEngine.newFunction( QErfc             ));
//  /*  35   */ mEngine.globalObject().setProperty( "tgamma",           mEngine.newFunction( QTgamma           ));
    /*  36   */ mEngine.globalObject().setProperty( "lgamma",           mEngine.newFunction( QLgamma           ));
    /*  37   */ mEngine.globalObject().setProperty( "ceil",             mEngine.newFunction( QCeil             ));
    /*  38   */ mEngine.globalObject().setProperty( "floor",            mEngine.newFunction( QFloor            ));
    /*  39   */ mEngine.globalObject().setProperty( "fmod",             mEngine.newFunction( QFmod             ));
    /*  40   */ mEngine.globalObject().setProperty( "trunc",            mEngine.newFunction( QTrunc            ));
    /*  41   */ mEngine.globalObject().setProperty( "round",            mEngine.newFunction( QRound            ));
//  /*  42   */ mEngine.globalObject().setProperty( "lround",           mEngine.newFunction( QLround           ));
//  /*  43   */ mEngine.globalObject().setProperty( "llround",          mEngine.newFunction( QLlround          ));
    /*  44   */ mEngine.globalObject().setProperty( "rint",             mEngine.newFunction( QRint             ));
//  /*  45   */ mEngine.globalObject().setProperty( "lrint",            mEngine.newFunction( QLrint            ));
//  /*  46   */ mEngine.globalObject().setProperty( "llrint",           mEngine.newFunction( QLlrint           ));
    /*  47   */ mEngine.globalObject().setProperty( "nearbyint",        mEngine.newFunction( QNearbyint        ));
    /*  48   */ mEngine.globalObject().setProperty( "remainder",        mEngine.newFunction( QRemainder        ));
//  /*  49   */ mEngine.globalObject().setProperty( "remquo",           mEngine.newFunction( QRemquo           ));
    /*  50   */ mEngine.globalObject().setProperty( "copysign",         mEngine.newFunction( QCopysign         ));
    /*  51   */ mEngine.globalObject().setProperty( "nan",              mEngine.newFunction( QNan              ));
    /*  52   */ mEngine.globalObject().setProperty( "nextafter",        mEngine.newFunction( QNextafter        ));
    /*  53   */ mEngine.globalObject().setProperty( "nexttoward",       mEngine.newFunction( QNexttoward       ));
    /*  54   */ mEngine.globalObject().setProperty( "fdim",             mEngine.newFunction( QFdim             ));
    /*  55   */ mEngine.globalObject().setProperty( "fmax",             mEngine.newFunction( QFmax             ));
    /*  56   */ mEngine.globalObject().setProperty( "fmin",             mEngine.newFunction( QFmin             ));
    /*  57   */ mEngine.globalObject().setProperty( "fabs",             mEngine.newFunction( QFabs             ));
    /*  58   */ mEngine.globalObject().setProperty( "abs",              mEngine.newFunction( QAbs              ));
    /*  59   */ mEngine.globalObject().setProperty( "fma",              mEngine.newFunction( QFma              ));
    /*  60   */ mEngine.globalObject().setProperty( "fpclassify",       mEngine.newFunction( QFpclassify       ));
    /*  61   */ mEngine.globalObject().setProperty( "isfinite",         mEngine.newFunction( QIsfinite         ));
    /*  62   */ mEngine.globalObject().setProperty( "isinf",            mEngine.newFunction( QIsinf            ));
    /*  63   */ mEngine.globalObject().setProperty( "isnan",            mEngine.newFunction( QIsnan            ));
    /*  64   */ mEngine.globalObject().setProperty( "isnormal",         mEngine.newFunction( QIsnormal         ));
    /*  65   */ mEngine.globalObject().setProperty( "signbit",          mEngine.newFunction( QSignbit          ));
    /*  66   */ mEngine.globalObject().setProperty( "isgreater",        mEngine.newFunction( QIsgreater        ));
    /*  67   */ mEngine.globalObject().setProperty( "isgreaterequal",   mEngine.newFunction( QIsgreaterequal   ));
    /*  68   */ mEngine.globalObject().setProperty( "isless",           mEngine.newFunction( QIsless           ));
    /*  69   */ mEngine.globalObject().setProperty( "islessequal",      mEngine.newFunction( QIslessequal      ));
    /*  70   */ mEngine.globalObject().setProperty( "islessgreater",    mEngine.newFunction( QIslessgreater    ));
    /*  71   */ mEngine.globalObject().setProperty( "isunordered",      mEngine.newFunction( QIsunordered      ));
    /*  72   */ mEngine.globalObject().setProperty( "math_errhandling", mEngine.newFunction( QMath_errhandling ));
    /*  73   */ mEngine.globalObject().setProperty( "INFINITY",         mEngine.newFunction( QINFINITY         ));
    /*  74   */ mEngine.globalObject().setProperty( "NAN",              mEngine.newFunction( QNAN              ));
    /*  75   */ mEngine.globalObject().setProperty( "HUGE_VAL ",        mEngine.newFunction( QHUGE_VAL         ));
    /*  76   */ mEngine.globalObject().setProperty( "HUGE_VALF",        mEngine.newFunction( QHUGE_VALF        ));
    /*  77   */ mEngine.globalObject().setProperty( "HUGE_VALL",        mEngine.newFunction( QHUGE_VALL        ));
    /*  78   */ mEngine.globalObject().setProperty( "double_t",         mEngine.newFunction( QDouble_t         ));
    /*  79   */ mEngine.globalObject().setProperty( "float_t",          mEngine.newFunction( QFloat_t          ));
}
