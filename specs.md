# GDPR/AI Risk Assessment Tool

## Who It's For

This tool is mainly built for young students or small teams working on an AI project to check how risky their project can be from a GDPR/governance perspective. It is not a legal tool but only does some basic checks.

## What It Checks

- Do you actually have a legal reason to use people's data?
- Do you have a list of the data you're going to use and why?
- Is this AI doing anything like profiling people or using health data
- if doing anything like profiling or processing sensitive information, is the DPIA done.
- Is the data protected (passwords,ecryption)
- If by chance the date leaks, do you know what to do

### AI Risk Questions:

- How likely is something bad to happen? (1=low, 3=high)
- The impact if something happens. (1=low, 3=high)

## Scoring

- 0-3 = low risk
- 4-6 = medium risk
- 7+ = high risk

**RED flags** (automatic High risk)

- no legal basis or legal reason to process the data
- processing sensitive data without doing DPIA

## Disclaimer

- This is being built as a helper tool while i am learning about governance while prracticing C++. Not Legal Advice.
