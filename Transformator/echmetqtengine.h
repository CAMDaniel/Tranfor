#ifndef ECHMETQTENGINE_H
#define ECHMETQTENGINE_H

#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValue>
#include <algorithm>
#include <functional>
#include <cmath>
#include <QString>

typedef struct QScriptValue QVal;
typedef struct QScriptContext QCon;
typedef struct QScriptEngine QEng;

class EchmetQtEngine
{
public: //constructor
    EchmetQtEngine();
    EchmetQtEngine(double var);
    EchmetQtEngine(double var, QString charVar);
    EchmetQtEngine(QString func);

public: //set
    void    setVar  (double var);
    void    setChar (QString charVar);
    void    setFunc (QString func);

public: //get
    double  getVar  (void)         {   return mVar;             }
    double  getRes  (void)         {   return mRes.toNumber();  }
    QString getChar (void)         {   return mCharVar;         }
    QString getFunc (void)         {   return mFunc;            }

public: //other
    void    solve(QString func);
    void registerFunction(QString name, double (*func)(double));
    void registerFunction(QString name, double constant);

private:
    QEng    mEngine;
    QVal    mRes;
    QString mFunc;
    double  mVar;
    QString mCharVar;

private:
    void globalSettings();
    void setGlobalEngine();

private:
//  Trigonometric function
    static QVal QCos        (QCon * cxt, QEng *) {   return cos(cxt->argument(0).toNumber()); }
    static QVal QSin        (QCon * cxt, QEng *) {   return sin(cxt->argument(0).toNumber()); }
    static QVal QTan        (QCon * cxt, QEng *) {   return tan(cxt->argument(0).toNumber()); }
    static QVal QAcos       (QCon * cxt, QEng *) {   return acos(cxt->argument(0).toNumber()); }
    static QVal QAsin       (QCon * cxt, QEng *) {   return asin(cxt->argument(0).toNumber()); }
    static QVal QAtan       (QCon * cxt, QEng *) {   return atan(cxt->argument(0).toNumber()); }
    static QVal QAtan2      (QCon * cxt, QEng *) {   return atan2(cxt->argument(0).toNumber(),
                                                                      cxt->argument(1).toNumber()); }

//  Hyperbolic functions
    static QVal QCosh       (QCon * cxt, QEng *) {   return cosh(cxt->argument(0).toNumber()); }
    static QVal QSinh       (QCon * cxt, QEng *) {   return sinh(cxt->argument(0).toNumber()); }
    static QVal QTanh       (QCon * cxt, QEng *) {   return tanh(cxt->argument(0).toNumber()); }
    static QVal QAcosh      (QCon * cxt, QEng *) {   return acosh(cxt->argument(0).toNumber()); }
    static QVal QAsinh      (QCon * cxt, QEng *) {   return asinh(cxt->argument(0).toNumber()); }
    static QVal QAtanh      (QCon * cxt, QEng *) {   return atanh(cxt->argument(0).toNumber()); }

//  Exponential and logarithmic functions
    static QVal QExp        (QCon * cxt, QEng *) {   return exp(cxt->argument(0).toNumber()); }
///*  16   */    QVal QFrexp      (QCon * cxt, QEng *) {   return frexp(cxt->argument(0).toNumber(),
//                                                                     (cxt->argument(1).toNumber())); }
    static QVal QLdexp      (QCon * cxt, QEng *) {   return ldexp(cxt->argument(0).toNumber(),
                                                           cxt->argument(1).toInteger());  }
    static QVal QLog        (QCon * cxt, QEng *) {   return log(cxt->argument(0).toNumber()); }
    static QVal QLog10      (QCon * cxt, QEng *) {   return log10(cxt->argument(0).toNumber()); }
///*  20   */    QVal QModf       (QCon * cxt, QEng *) {   return modf(cxt->argument(0).toNumber()); }
    static QVal QExp2       (QCon * cxt, QEng *) {   return exp2(cxt->argument(0).toNumber()); }
    static QVal QExpm1      (QCon * cxt, QEng *) {   return expm1(cxt->argument(0).toNumber()); }
    static QVal QILogb      (QCon * cxt, QEng *) {   return ilogb(cxt->argument(0).toNumber()); }
    static QVal QLog1p      (QCon * cxt, QEng *) {   return log1p(cxt->argument(0).toNumber()); }
    static QVal QLog2       (QCon * cxt, QEng *) {   return log2(cxt->argument(0).toNumber()); }
    static QVal QLogb       (QCon * cxt, QEng *) {   return logb(cxt->argument(0).toNumber()); }
    static QVal QScalbn     (QCon * cxt, QEng *) {   return scalbn(cxt->argument(0).toNumber(),
                                                                              cxt->argument(1).toInteger()); }
    static QVal QScalbln    (QCon * cxt, QEng *) {   return scalbln(cxt->argument(0).toNumber(),
                                                                               cxt->argument(1).toInteger()); }

//  Power function
    static QVal QPow        (QCon * cxt, QEng *) {   return pow(cxt->argument(0).toNumber(),
                                                                cxt->argument(1).toNumber()); }
    static QVal QSqrt       (QCon * cxt, QEng *) {   return sqrt(cxt->argument(0).toNumber()); }
    static QVal QCbrt       (QCon * cxt, QEng *) {   return cbrt(cxt->argument(0).toNumber()); }
    static QVal QHypot      (QCon * cxt, QEng *) {   return hypot(cxt->argument(0).toNumber(),
                                                                  cxt->argument(1).toNumber()); }

//  Error and gamma functions
    static QVal QErf        (QCon * cxt, QEng *) {   return erf(cxt->argument(0).toNumber()); }
    static QVal QErfc       (QCon * cxt, QEng *) {   return erfc(cxt->argument(0).toNumber()); }
    static QVal QTgammma    (QCon * cxt, QEng *) {   return tgamma(cxt->argument(0).toNumber()); }
    static QVal QLgamma     (QCon * cxt, QEng *) {   return lgamma(cxt->argument(0).toNumber()); }

//  Rounding and remainder functions
    static QVal QCeil       (QCon * cxt, QEng *) {   return ceil(cxt->argument(0).toNumber()); }
    static QVal QFloor      (QCon * cxt, QEng *) {   return floor(cxt->argument(0).toNumber()); }
    static QVal QFmod       (QCon * cxt, QEng *) {   return fmod(cxt->argument(0).toNumber(),
                                                                 cxt->argument(1).toNumber()); }
    static QVal QTrunc      (QCon * cxt, QEng *) {   return trunc(cxt->argument(0).toNumber()); }
    static QVal QRound      (QCon * cxt, QEng *) {   return round(cxt->argument(0).toNumber()); }
///*  42   */   static QVal QLRound     (QCon * cxt, QEng *) {   return lround((int)cxt->argument(0).toNumber()); }
///*  43   */   static QVal QLlround    (QCon * cxt, QEng *) {   return llround(cxt->argument(0).toNumber()); }
    static QVal QRint       (QCon * cxt, QEng *) {   return rint(cxt->argument(0).toNumber()); }
///*  45   */   static QVal QLRint      (QCon * cxt, QEng *) {   return lrint(cxt->argument(0).toNumber()); }
///*  46   */   static QVal QLlrint     (QCon * cxt, QEng *) {   return llrint(cxt->argument(0).toNumber()); }
    static QVal QNearbyint  (QCon * cxt, QEng *) {   return nearbyint(cxt->argument(0).toNumber()); }
    static QVal QRemainder  (QCon * cxt, QEng *) {   return remainder(cxt->argument(0).toNumber(),
                                                                                 cxt->argument(1).toNumber()); }
///*  49   */   static QVal QRemquo     (QCon * cxt, QEng *) {   return remquo(cxt->argument(0).toNumber(),
//                                                                            cxt->argument(1).toNumber()
//                                                                            (int)cxt->argument(2).toNumber()); }

//  Floating-point manipulation functions
    static QVal QCopysign   (QCon * cxt, QEng *) {   return copysign(cxt->argument(0).toNumber(), cxt->argument(1).toNumber()); }
    static QVal QNan        (QCon * cxt, QEng *) {   return nan(cxt->argument(0).toString().toStdString().c_str()); }
    static QVal QNextafter  (QCon * cxt, QEng *) {   return nextafter(cxt->argument(0).toNumber(), cxt->argument(1).toNumber()); }
    static QVal QNexttoward (QCon * cxt, QEng *) {   return nexttoward(cxt->argument(0).toNumber(), cxt->argument(1).toNumber()); }

//  Minimum, maximum, difference functions
    static QVal QFdim       (QCon * cxt, QEng *) {   return fdim(cxt->argument(0).toNumber(), cxt->argument(1).toNumber()); }
    static QVal QFmax       (QCon * cxt, QEng *) {   return fmax(cxt->argument(0).toNumber(), cxt->argument(1).toNumber()); }
    static QVal QFmin       (QCon * cxt, QEng *) {   return fmin(cxt->argument(0).toNumber(), cxt->argument(1).toNumber()); }

//  Other function
    static QVal QFabs       (QCon * cxt, QEng *) {   return fabs(cxt->argument(0).toNumber()); }
    static QVal QAbs        (QCon * cxt, QEng *) {   return abs(cxt->argument(0).toNumber()); }
    static QVal QFma        (QCon * cxt, QEng *) {   return fma(cxt->argument(0).toNumber(),
                                                                           cxt->argument(1).toNumber(),
                                                                           cxt->argument(2).toNumber()); }

//  Classification macro/functions
    static QVal QFpclassify (QCon * cxt, QEng *) {   return std::fpclassify(cxt->argument(0).toNumber()); }
    static QVal QIsfinite   (QCon * cxt, QEng *) {   return std::isfinite(cxt->argument(0).toNumber()); }
    static QVal QIsinf      (QCon * cxt, QEng *) {   return std::isinf(cxt->argument(0).toNumber()); }
    static QVal QIsnan      (QCon * cxt, QEng *) {   return std::isnan(cxt->argument(0).toNumber()); }
    static QVal QIsnormal   (QCon * cxt, QEng *) {   return std::isnormal(cxt->argument(0).toNumber()); }
    static QVal QSignbit    (QCon * cxt, QEng *) {   return std::signbit(cxt->argument(0).toNumber()); }

//  Comparison macro/functions
    static QVal QIsgreater          (QCon * cxt, QEng *) {   return std::isgreater(cxt->argument(0).toNumber(),
                                                                                   cxt->argument(1).toNumber()); }
    static QVal QIsgreaterequal     (QCon * cxt, QEng *) {   return std::isgreaterequal(cxt->argument(0).toNumber(),
                                                                                        cxt->argument(1).toNumber()); }
    static QVal QIsless             (QCon * cxt, QEng *) {   return std::isless(cxt->argument(0).toNumber(),
                                                                                cxt->argument(1).toNumber()); }
    static QVal QIslessequal        (QCon * cxt, QEng *) {   return std::islessequal(cxt->argument(0).toNumber(),
                                                                                     cxt->argument(1).toNumber()); }
    static QVal QIslessgreater      (QCon * cxt, QEng *) {   return std::islessgreater(cxt->argument(0).toNumber(),
                                                                                       cxt->argument(1).toNumber()); }
    static QVal QIsunordered        (QCon * cxt, QEng *) {   return std::isunordered(cxt->argument(0).toNumber(),
                                                                                                cxt->argument(1).toNumber()); }

//  Macro constants
    static QVal QMath_errhandling   (QCon *, QEng *) {   return math_errhandling; }
    static QVal QINFINITY           (QCon *, QEng *) {   return INFINITY; }
    static QVal QNAN                (QCon *, QEng *) {   return NAN; }
    static QVal QHUGE_VAL           (QCon *, QEng *) {   return HUGE_VAL; }
    static QVal QHUGE_VALF          (QCon *, QEng *) {   return HUGE_VALF; }
    static QVal QHUGE_VALL          (QCon *, QEng *) {   return (double)HUGE_VALL; }

//  Types
    static QVal QDouble_t   (QCon * cxt, QEng *) {   return double_t(cxt->argument(0).toNumber()); }
    static QVal QFloat_t    (QCon * cxt, QEng *) {   return float_t(cxt->argument(0).toNumber()); }
};

#endif // ECHMETQTENGINE_H
