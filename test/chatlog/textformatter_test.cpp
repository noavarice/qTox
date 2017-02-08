#include "src/chatlog/textformatter.h"

#include "check.h"
#include "test/common.h"

#include <QString>
#include <QMap>


const QMap<QString, QString> SINGLE_SIGN_BOLD_TEST_WITHOUT_FORMATTING_SMB {
    { "*lorem ipsum!*", "<b>lorem ipsum!</b>" },
    { "* lorem ipsum!*", "* lorem ipsum!*" },
    { "*lorem ipsum! *", "*lorem ipsum! *" },
    { "* lorem ipsum! *", "* lorem ipsum! *" },

    { "lorem *lorem ipsum!*", "lorem <b>lorem ipsum!</b>" },
    { "*lorem ipsum!* ipsum", "<b>lorem ipsum!</b> ipsum" },
    { "lorem *lorem ipsum!* ipsum", "lorem <b>lorem ipsum!</b> ipsum" },
};

const QMap<QString, QString> SINGLE_SIGN_BOLD_TEST_WITH_FORMATTING_SMB {
    { "*lorem ipsum!*", "*<b>lorem ipsum!</b>*" },
    { "* lorem ipsum!*", "* lorem ipsum!*" },
    { "*lorem ipsum! *", "*lorem ipsum! *" },
    { "* lorem ipsum! *", "* lorem ipsum! *" },

    { "lorem *lorem ipsum!*", "lorem *<b>lorem ipsum!</b>*" },
    { "*lorem ipsum!* ipsum", "*<b>lorem ipsum!</b>* ipsum" },
    { "lorem *lorem ipsum!* ipsum", "lorem *<b>lorem ipsum!</b>* ipsum" },
};

START_TEST(boldFontWithoutFormattingSmbTest)
{
    for (auto pair = SINGLE_SIGN_BOLD_TEST_WITHOUT_FORMATTING_SMB.begin(); pair != SINGLE_SIGN_BOLD_TEST_WITHOUT_FORMATTING_SMB.end(); ++pair) {
        TextFormatter tf = TextFormatter(pair.key());
        ck_assert(tf.applyStyling(true) == pair.value());
    }
}
END_TEST

START_TEST(boldFontWithFormattingSmbTest)
{
    for (auto pair = SINGLE_SIGN_BOLD_TEST_WITH_FORMATTING_SMB.begin(); pair != SINGLE_SIGN_BOLD_TEST_WITH_FORMATTING_SMB.end(); ++pair) {
        TextFormatter tf = TextFormatter(pair.key());
        ck_assert(tf.applyStyling(false) == pair.value());
    }
}
END_TEST

static Suite *textFormatterSuite(void)
{
    Suite *s = suite_create("TextFormatter");

    DEFTESTCASE(boldFontWithoutFormattingSmb);
    DEFTESTCASE(boldFontWithFormattingSmb);

    return s;
}

int main(int argc, char *argv[])
{
    srand((unsigned int) time(NULL));

    Suite *textFormatter = textFormatterSuite();
    SRunner *runner = srunner_create(textFormatter);
    srunner_run_all(runner, CK_NORMAL);

    int res = srunner_ntests_failed(runner);
    srunner_free(runner);

    return res;
}
