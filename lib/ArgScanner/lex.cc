// Generated by Flexc++ V2.11.00 on Wed, 05 Apr 2023 14:50:41 +0200

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <filesystem>

// $insert class_ih
#include "ArgScanner.ih"


    // s_ranges_: use (unsigned) characters as index to obtain
    //           that character's range-number.
    //           The range for EOF is defined in a constant in the
    //           class header file
size_t const ArgScannerBase::s_ranges_[] =
{
     0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
     4, 4, 4, 4, 4, 4, 4, 5, 6, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9,10,10,11,11,
    11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
    12,12,12,12,12,12,
};

// $insert startcondinfo
    // s_dfa_ contains the rows of *all* DFAs ordered by start state.  The
    // enum class StartCondition_is defined in the baseclass header.
    // StartCondition_::INITIAL is always 0.  Each entry defines the row to
    // transit to if the column's character range was sensed. Row numbers are
    // relative to the used DFA, and d_dfaBase_ is set to the first row of
    // the subset to use.  The row's final two values are respectively the
    // rule that may be matched at this state, and the rule's FINAL flag. If
    // the final value equals FINAL (= 1) then, if there's no continuation,
    // the rule is matched. If the BOL flag (8) is also set (so FINAL + BOL (=
    // 9) is set) then the rule only matches when d_atBOL is also true.
int const ArgScannerBase::s_dfa_[][16] =
{
    // INITIAL
    { 1, 2, 2, 2, 1, 2, 1, 3, 1, 4, 1, 5, 1,-1,    -1, -1},  // 0
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1,-1,     3, -1},  // 1
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1,-1,     0, -1},  // 2
    { 7, 7, 7, 7, 7, 7, 7, 7, 7, 6, 7, 7, 7,-1,     3, -1},  // 3
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     4, -1},  // 4
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 1, 5, 1,-1,     1, -1},  // 5
    { 6, 6,-1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,-1,     3, -1},  // 6
    { 7, 7, 7, 7, 7, 7, 7, 8, 7, 9, 7, 7, 7,-1,     3, -1},  // 7
    { 7, 7, 7, 7, 7, 7, 7, 8, 7, 9, 7, 7, 7,-1,     2, -1},  // 8
    { 9, 9,-1, 9, 9, 9, 9,10, 9, 9, 9, 9, 9,-1,     3, -1},  // 9
    { 9, 9,-1, 9, 9, 9, 9,10, 9, 9, 9, 9, 9,-1,     2, -1},  // 10
    // flag
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,-1,    -1, -1},  // 0
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,     5, -1},  // 1
};


int const (*ArgScannerBase::s_dfaBase_[])[16] =
{
    s_dfa_ + 0,
    s_dfa_ + 11,
};

size_t ArgScannerBase::s_istreamNr = 0;

// $insert inputImplementation
ArgScannerBase::Input::Input()
:
    d_in(0),
    d_lineNr(1)
{}

ArgScannerBase::Input::Input(std::istream *iStream, size_t lineNr)
:
    d_in(iStream),
    d_lineNr(lineNr)
{}

size_t ArgScannerBase::Input::get()
{
    switch (size_t ch = next())         // get the next input char
    {
        case '\n':
            ++d_lineNr;
        [[fallthrough]];

        default:
        return ch;
    }
}

size_t ArgScannerBase::Input::next()
{
    size_t ch;

    if (d_deque.empty())                // deque empty: next char fm d_in
    {
        if (d_in == 0)
            return AT_EOF;
        ch = d_in->get();
        return *d_in ? ch : static_cast<size_t>(AT_EOF);
    }

    ch = d_deque.front();
    d_deque.pop_front();

    return ch;
}

void ArgScannerBase::Input::reRead(size_t ch)
{
    if (ch < 0x100)
    {
        if (ch == '\n')
            --d_lineNr;
        d_deque.push_front(ch);
    }
}

void ArgScannerBase::Input::reRead(std::string const &str, size_t fm)
{
    for (size_t idx = str.size(); idx-- > fm; )
        reRead(str[idx]);
}

ArgScannerBase::ArgScannerBase(std::istream &in, std::ostream &out, bool keepCwd)
:
    d_out(new std::ostream(out.rdbuf())),
// $insert interactiveInit
    d_in(0),
    d_dfaBase_(s_dfa_)
{
    if (keepCwd)
        d_cwd = std::filesystem::current_path().string();
    p_pushStream(s_istream, new std::istream(in.rdbuf()));
}

void ArgScannerBase::switchStream_(std::istream &in, size_t lineNr)
{
    d_input->close();
    d_streamStack.back().input = { new std::istream(in.rdbuf()), lineNr };
}


ArgScannerBase::ArgScannerBase(std::string const &infilename, std::string const &outfilename, bool keepCwd)
:
    d_out(outfilename == "-"    ? new std::ostream(std::cout.rdbuf()) :
          outfilename == ""     ? new std::ostream(std::cerr.rdbuf()) :
                                  new std::ofstream(outfilename)),
    d_dfaBase_(s_dfa_)
{
    if (keepCwd)
        d_cwd = std::filesystem::current_path().string();

    p_pushStream(infilename, { new std::ifstream(infilename) });
    toCwd();
}

void ArgScannerBase::switchStreams(std::istream &in, std::ostream &out)
{
    switchStream_(in, 1);
    switchOstream(out);
}

void ArgScannerBase::switchIstream(std::string const &infilename)
{
    d_input->close();
    d_filename = infilename;

    d_streamStack.back() = 
        StreamStruct{ chgWorkingDir(d_filename), 
                      { new std::ifstream(infilename) } };

    d_atBOL = true;
}

void ArgScannerBase::switchStreams(std::string const &infilename,
                           std::string const &outfilename)
{
    switchOstream(outfilename);
    switchIstream(infilename);
}

void ArgScannerBase::pushStream(std::istream  &istr)
{
    p_pushStream("(istream)", new std::istream(istr.rdbuf())); //streamPtr);
}

void ArgScannerBase::pushStream(std::string const &name)
{
    std::istream *streamPtr = new std::ifstream(name);
    if (!*streamPtr)
    {
        delete streamPtr;
        throw std::runtime_error("Cannot read " + name);
    }
    p_pushStream(name, streamPtr);
}



void ArgScannerBase::toCwd() const
{
    using namespace std;
    using namespace filesystem;

    if (d_cwd.empty())
        return;

    error_code ec;
    current_path(d_cwd, ec);
};

// static
std::string ArgScannerBase::chgWorkingDir(std::string const &name)     // any name
{
    using namespace std;
    using namespace filesystem;

    if (name == s_istream)                              // used with istreams
        return name;
                                                        // a filename: get its
    auto path = absolute(name);                         // full pathname

    error_code ec;
    current_path(path.parent_path(), ec);

    return path.string();                               // return the pathname
}

void ArgScannerBase::p_pushStream(std::string const &name, std::istream *streamPtr)
{
    if (d_streamStack.size() == s_maxSizeofStreamStack_)
    {
        delete streamPtr;
        throw std::length_error("Max stream stack size exceeded");
    }

    d_filename = name;
    d_streamStack.push_back(
                    StreamStruct{chgWorkingDir(d_filename), { streamPtr } }
                  );

    d_input = &d_streamStack.back().input;

    d_atBOL = true;
}

void ArgScannerBase::switchOstream(std::ostream &out)
{
    *d_out << std::flush;
    d_out.reset(new std::ostream(out.rdbuf()));
}

// $insert debugFunctions
void ArgScannerBase::setDebug(bool onOff)
{}

bool ArgScannerBase::debug() const
{
    return false;
}

void ArgScannerBase::redo(size_t nChars)
{
    size_t from = nChars >= length() ? 0 : length() - nChars;
    d_input->reRead(d_matched, from);
    d_matched.resize(from);
}

void ArgScannerBase::switchOstream(std::string const &outfilename)
{
    *d_out << std::flush;
    d_out.reset(
            outfilename == "-"    ? new std::ostream(std::cout.rdbuf()) :
            outfilename == ""     ? new std::ostream(std::cerr.rdbuf()) :
                                    new std::ofstream(outfilename));
}


bool ArgScannerBase::popStream()
{
    using namespace std::filesystem;

    d_input->close();

    if (d_streamStack.size() <= 1)
        return false;

    d_streamStack.pop_back();

    d_filename = path{ chgWorkingDir(d_streamStack.back().pushedName) 
                     }.filename().string();

    d_input = &d_streamStack.back().input;

    return true;
}



  // See the manual's section `Run-time operations' section for an explanation
  // of this member.
ArgScannerBase::ActionType_ ArgScannerBase::actionType_(size_t range)
{
    d_nextState = d_dfaBase_[d_state][range];

    if (d_nextState != -1)                  // transition is possible
        return ActionType_::CONTINUE;

    if (knownFinalState())                  // FINAL state reached
        return ActionType_::MATCH;         

    if (d_matched.size())
        return ActionType_::ECHO_FIRST;    // no match, echo the 1st char

    return range != s_rangeOfEOF_ ? 
                ActionType_::ECHO_CH 
            : 
                ActionType_::RETURN;
}

void ArgScannerBase::accept(size_t nChars)          // old name: less
{
    if (nChars < d_matched.size())
    {
        d_input->reRead(d_matched, nChars);
        d_matched.resize(nChars);
    }
}

void ArgScannerBase::setMatchedSize(size_t length)
{
    d_input->reRead(d_matched, length);  // reread the tail section
    d_matched.resize(length);           // return what's left
}

  // At this point a rule has been matched.  The next character is not part of
  // the matched rule and is sent back to the input.  The final match length
  // is determined, the index of the matched rule is determined, and then
  // d_atBOL is updated. Finally the rule's index is returned.
  // The numbers behind the finalPtr assignments are explained in the 
  // manual's `Run-time operations' section.
size_t ArgScannerBase::matched_(size_t ch)
{
    d_input->reRead(ch);

    FinalData *finalPtr;
                            
    if (not d_atBOL)                    // not at BOL
        finalPtr = &d_final.std;        // then use the std rule (3, 4)

                                        // at BOL
    else if (not available(d_final.std.rule))   // only a BOL rule avail.
            finalPtr = &d_final.bol;            // use the BOL rule (6)

    else if (not available(d_final.bol.rule)) // only a std rule is avail.
        finalPtr = &d_final.std;        // use the std rule (7)
        
    else if (                           // Both are available (8)
        d_final.bol.length !=           // check lengths of matched texts
        d_final.std.length              // unequal lengths, use the rule
    )                                   // having the longer match length
        finalPtr =              
            d_final.bol.length > d_final.std.length ?
                &d_final.bol
            :
                &d_final.std;

    else                            // lengths are equal: use 1st rule
        finalPtr = 
            d_final.bol.rule < d_final.std.rule ?
                &d_final.bol
            :
                &d_final.std;

    setMatchedSize(finalPtr->length);

    d_atBOL = d_matched.back() == '\n';


    return finalPtr->rule;
}

size_t ArgScannerBase::getRange_(int ch)       // using int to prevent casts
{
    return ch == AT_EOF ? as<size_t>(s_rangeOfEOF_) : s_ranges_[ch];
}

  // At this point d_nextState contains the next state and continuation is
  // possible. The just read char. is appended to d_match
void ArgScannerBase::continue_(int ch)
{
    d_state = d_nextState;

    if (ch != AT_EOF)
        d_matched += ch;
}

void ArgScannerBase::echoCh_(size_t ch)
{
    *d_out << as<char>(ch);
    d_atBOL = ch == '\n';
}


   // At this point there is no continuation. The last character is
   // pushed back into the input stream as well as all but the first char. in
   // the buffer. The first char. in the buffer is echoed to stderr. 
   // If there isn't any 1st char yet then the current char doesn't fit any
   // rules and that char is then echoed
void ArgScannerBase::echoFirst_(size_t ch)
{
    d_input->reRead(ch);
    d_input->reRead(d_matched, 1);
    echoCh_(d_matched[0]);
}

    // Update the rules associated with the current state, do this separately
    // for BOL and std rules.
    // If a rule was set, update the rule index and the current d_matched
    // length. 
void ArgScannerBase::updateFinals_()
{
    size_t len = d_matched.size();

    int const *rf = d_dfaBase_[d_state] + s_finIdx_;

    if (rf[0] != -1)        // update to the latest std rule
    {
        d_final.std = FinalData { as<size_t>(rf[0]), len };
    }

    if (rf[1] != -1)        // update to the latest bol rule
    {
        d_final.bol = FinalData { as<size_t>(rf[1]), len };
    }
}

void ArgScannerBase::reset_()
{
    d_final = Final{ 
                    FinalData{s_unavailable, 0}, 
                    FinalData {s_unavailable, 0} 
                };

    d_state = 0;
    d_return = true;

    if (!d_more)
        d_matched.clear();

    d_more = false;
}

int ArgScanner::executeAction_(size_t ruleIdx)
try
{
    switch (ruleIdx)
    {
        // $insert actions
        case 1:
        {
#line 10 "lexer"
            return Tokens::INT;
        }
        break;
        case 2:
        {
#line 11 "lexer"
            return Tokens::STRING;
        }
        break;
        case 3:
        {
#line 12 "lexer"
            return Tokens::TEXT;
        }
        break;
        case 4:
        {
#line 13 "lexer"
            {
                begin(StartCondition_::flag);
                return matched().front();
            }
        }
        break;
        case 5:
        {
#line 22 "lexer"
            {
                begin(StartCondition_::INITIAL);
                return matched().front();
            }
        }
        break;
    }
    noReturn_();
    return 0;
}
catch (Leave_ value)
{
    return static_cast<int>(value);
}

int ArgScanner::lex_()
{
    reset_();
    preCode();

    while (true)
    {
        size_t ch = get_();                // fetch next char
        size_t range = getRange_(ch);      // determine the range

        updateFinals_();                    // update the state's Final info

        switch (actionType_(range))        // determine the action
        {
            case ActionType_::CONTINUE:
                continue_(ch);
            continue;

            case ActionType_::MATCH:
            {
                d_token_ = executeAction_(matched_(ch));
                if (return_())
                {
                    print();
                    toCwd();
                    return d_token_;
                }
                break;
            }

            case ActionType_::ECHO_FIRST:
                echoFirst_(ch);
            break;

            case ActionType_::ECHO_CH:
                echoCh_(ch);
            break;

            case ActionType_::RETURN:
                if (!popStream())
                {
                     postCode(PostEnum_::END);
                     toCwd();
                     return 0;
                }
                postCode(PostEnum_::POP);
             continue;
        } // switch

        postCode(PostEnum_::WIP);

        reset_();
        preCode();
    } // while
}

void ArgScannerBase::print_() const
{
}


