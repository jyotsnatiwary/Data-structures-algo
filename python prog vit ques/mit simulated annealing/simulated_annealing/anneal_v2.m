% Revision:
% - 02.06.2016, EG: - Record the BEST instead of the last x values
%                     at the end of every cycle (and the corresponding
%                     objective)


clc;
clear;
close all;

%% Generate a contour plot
% Start location
x_start = [0.8, -0.5];

% Design variables at mesh points
i1 = -1.0:0.01:1.0;
i2 = -1.0:0.01:1.0;
[x1m, x2m] = meshgrid(i1, i2);
fm = 0.2 + x1m.^2 + x2m.^2 - 0.1*cos(6.0*pi*x1m) - 0.1*cos(6.0*pi*x2m);

% Contour Plot
fig = figure(1);
[C,h] = contour(x1m,x2m,fm);
clabel(C,h,'Labelspacing',250);
title('Simulated Annealing');
xlabel('x1');
ylabel('x2');
hold on;

%% Simulated Annealing

% Number of cycles
n = 50;
% Number of trials per cycle
m = 50;
% Number of accepted solutions
na = 0.0;
% Probability of accepting worse solution at the start
p1 = 0.7;
% Probability of accepting worse solution at the end
p50 = 0.001;
% Initial temperature
t1 = -1.0/log(p1);
% Final temperature
t50 = -1.0/log(p50);
% Fractional reduction every cycle
frac = (t50/t1)^(1.0/(n-1.0));
% Initialize x
x = zeros(n+1,2);
x(1,:) = x_start;
xi = x_start;
na = na + 1.0;
% Current best results so far
% xc = x(1,:);                           % modified by E. Gauterin 10.06.2016
fc = f(xi);
fs = zeros(n+1,1);
fs(1,:) = fc;
% Current temperature
t = t1;
% DeltaE Average
DeltaE_avg = 0.0;
for i=1:n
    disp(['Cycle: ',num2str(i),' with Temperature: ',num2str(t)])
    xc(1) = x(i,1);                         % added by E. Gauterin 10.06.2016
    xc(2) = x(i,2);                         % added by E. Gauterin 10.06.2016
    for j=1:m
        % Generate new trial points
        xi(1) = xc(1) + rand() - 0.5;
        xi(2) = xc(2) + rand() - 0.5;
        % Clip to upper and lower bounds
        xi(1) = max(min(xi(1),1.0),-1.0);
        xi(2) = max(min(xi(2),1.0),-1.0);
        DeltaE = abs(f(xi)-fc);
        if (f(xi)>fc)
            %         % Initialize DeltaE_avg if a worse solution was found
            %         %   on the first iteration
            if (i==1 && j==1)
                DeltaE_avg = DeltaE;
            end
            % objective function is worse
            % generate probability of acceptance
            p = exp(-DeltaE/(DeltaE_avg * t));
            %             % determine whether to accept worse point
            if (rand()<p)
                % accept the worse solution
                accept = true;
            else
                % don't accept the worse solution
                accept = false;
            end
        else
            % objective function is lower, automatically accept
            accept = true;
        end
%        disp(['Cycle: ',num2str(i),' trial: ',num2str(j)]);
                                            % added by E. Gauterin 02.06.2016
%        accept                             % added by E. Gauterin 02.06.2016
        if (accept==true)
            % update currently accepted solution
%            disp(['Cycle i:', num2str(i)]);% added by E. Gauterin 02.06.2016
%            disp(['Trail j:', num2str(j)]);% added by E. Gauterin 02.06.2016
            xc(1) = xi(1);
%            fprintf('xc(1) (in %s. cycle, %s. trial): %s \n',...
%                num2str(i),num2str(j),num2str(xc(1)));
                                            % added by E. Gauterin 02.06.2016
            xc(2) = xi(2);
%            fprintf('xc(2) (in %s. cycle, %s. trial): %s \n',...
%                num2str(i),num2str(j),num2str(xc(2)));
                                            % added by E. Gauterin 02.06.2016
            fc = f(xc);
%            fprintf('fc    (in %s. cycle, %s. trial): %s \n',...
%                num2str(i),num2str(j),num2str(fc));
                                            % added by E. Gauterin 02.06.2016
            % Store ACCEPTED candidates xc and corresponding solution f(xc)
            xa(j,1) = xc(1);                % added by E. Gauterin 02.06.2016
            xa(j,2) = xc(2);                % added by E. Gauterin 02.06.2016
            fa(j) = f(xc);                  % added by E. Gauterin 02.06.2016
            % increment number of accepted solutions
            na = na + 1.0;
            % update DeltaE_avg
            DeltaE_avg = (DeltaE_avg * (na-1.0) +  DeltaE) / na;
        else
            fa(j) = 0.0;                    % added by E. Gauterin 02.06.2016
        end
    end
    % Record the best solution fa and corresponding candidates xa from the
    % stored values in the inner "trial" loop (at the end of every "trial"
    % cycle)
    fa_Min_Index = find(nonzeros(fa) == min(nonzeros(fa))); 
                                            % added by E. Gauterin 02.06.2016
    if isempty(fa_Min_Index) == 0           % added by E. Gauterin 02.06.2016
        x(i+1,1) = xa(fa_Min_Index,1);   % modified by E. Gauterin 02.06.2016
        x(i+1,2) = xa(fa_Min_Index,2);   % modified by E. Gauterin 02.06.2016
        fs(i+1)  = fa(fa_Min_Index);     % modified by E. Gauterin 02.06.2016
    else                                    % added by E. Gauterin 02.06.2016
        x(i+1,1) = x(i,1);                  % added by E. Gauterin 02.06.2016
        x(i+1,2) = x(i,2);                  % added by E. Gauterin 02.06.2016
        fs(i+1)  = fs(i);                   % added by E. Gauterin 02.06.2016
    end                                     % added by E. Gauterin 02.06.2016
    % Lower the temperature for next cycle
    t = frac * t;
    fa = 0.0;                               % added by E. Gauterin 02.06.2016
end
% print solution
disp(['Best candidate: ',num2str(xc)])
disp(['Best solution: ',num2str(fc)])
plot(x(:,1),x(:,2),'r-o')
saveas(fig,'contour','png')

fig = figure(2);
subplot(2,1,1)
plot(fs,'r.-')
legend('Objective')
subplot(2,1,2)
hold on
plot(x(:,1),'b.-')
plot(x(:,2),'g.-')
legend('x_1','x_2')

% Save the figure as a PNG
saveas(fig,'iterations','png')